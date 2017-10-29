import math
import sys

def solve():
    topic_id = {}
    i = 0
    books = []
    for line in sys.stdin:
        line = line.split()
        time = int(line[0])
        topics = line[1:]
        for topic in topics:
            if topic not in topic_id.keys():
                topic_id[topic] = i
                i += 1
        bitmask = 0
        for topic in topics:
            bitmask |= 1 << topic_id[topic]
        books.append((time, bitmask))
    subsets = 2**len(topic_id)
    arr = [[sys.maxint]*subsets for _ in xrange(2)]
    for i in range(2):
        arr[i][0] = 0
    for i in xrange(1, len(books)+1):
        time, bitmask = books[i-1]
        for j in xrange(1, subsets):
            prev = j & (~bitmask)
            # print j, prev
            if j == prev:
                arr[i&1][j] = arr[(i-1)&1][j]
            else:
                arr[i&1][j] = min(arr[(i-1)&1][j], time+arr[i&1][prev])
    # for line in arr:
    #     print arr
    print arr[len(books)&1][-1]


def main():
    solve()

if __name__ == "__main__":
    main()
