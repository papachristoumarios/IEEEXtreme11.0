import math


def visit(adj, visited, parent, i, ret=False):
    # print i
    if i in visited:
        return ret
    visited.add(i)
    for j in adj[i]:
        if j == parent:
            continue
        a = visit(adj, visited, i, j, ret=True)
        if a:
            # print i, a
            return a
    # print i, 0
    return 0

def solve():
    N, M = [int(i) for i in raw_input().split()]
    arr = [int(i) for i in raw_input().split()]
    adj = {}
    visited = set()
    for i in xrange(N):
        adj[i] = []
    for start, finish in zip(arr[::2], arr[1::2]):
        adj[start].append(finish)
        adj[finish].append(start)
    for i in xrange(N):
        if i in visited:
            continue
        # print "visiting", i
        if visit(adj, visited, -1, i):
            return 1
    return 0


def main():
    N = int(raw_input())
    for _ in xrange(N):
        print solve()

if __name__ == "__main__":
    main()
