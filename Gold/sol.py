import heapq
import sys

primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53]
bounds = [1]

for pr in primes:
    bounds.append(bounds[-1]*pr)


def gold(town_id):
    i = 0
    while bounds[i] <= town_id:
        i += 1
    return i - 1

def solve():
    N, M = [int(i) for i in raw_input().split()]
    ids = [int(raw_input()) for _ in xrange(N)]
    town_gold = {town_id: gold(town_id) for town_id in ids}
    adj = {}
    for i in ids:
        adj[i] = []
    for _ in xrange(M):
        i, j, w = [int(i) for i in raw_input().split()]
        adj[i].append((j, w))
        adj[j].append((i, w))
    start, end = min(ids), max(ids)
    visited = set()
    max_dist = sys.maxint/2
    min_dist = {town_id: max_dist for town_id in ids}
    min_dist[start] = 0
    queue = [(0, -gold(start), start)]
    while queue:
        curr_dist, curr_gold, curr_node = heapq.heappop(queue)
        if curr_node in visited:
            continue
        if curr_node == end:
            print -curr_gold
            break
        for next_node, dist in adj[curr_node]:
            if next_node in visited:
                continue
            next_dist = curr_dist + dist
            if min_dist[next_node] >= next_dist:
                min_dist[next_node] = next_dist
                heapq.heappush(queue, (next_dist, curr_gold-town_gold[next_node], next_node))

def main():
    solve()

if __name__ == "__main__":
    main()
