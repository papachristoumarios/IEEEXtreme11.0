import math
import sys
import numpy as np

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
    arr = 1000000000*np.ones((2, subsets), dtype=int)
    arr[:, 0] = 0
    for i in xrange(1, len(books)+1):
        time, bitmask = books[i-1]
        prev = np.arange(subsets) & (~bitmask)
        arr[i&1] = np.minimum(arr[(i-1)&1], time+arr[(i-1)&1, prev])
    print arr[len(books)&1][-1]


def main():
    solve()

if __name__ == "__main__":
    main()
