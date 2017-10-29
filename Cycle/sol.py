import math
import sys


def find(arr, i):
    # print i
    if arr[i] != i:
        arr[i] = find(arr, arr[i])
    return arr[i]

def union(arr, i1, i2, j1, j2):
    # print i1, i2, j1, j2
    if (arr[i1] != i1) or (arr[i2] != i2) or  (arr[j1] != j1) or (arr[j2] != j2):
        raise ValueError("Fucked up the union")
    arr[j1] = arr[i2]
    arr[j2] = arr[i1]


def main():
    N = int(raw_input())
    arr = range(2*N)
    adj = {}
    while True:
        a, b = [int(i)-1 for i in raw_input().split()]
        f_a1, f_a2, f_b1, f_b2 = find(arr, 2*a), find(arr, 2*a+1), find(arr, 2*b), find(arr, 2*b+1)
        if (f_a1 == f_b1) or (f_a2 == f_b2):
            print 0
            return
        union(arr, f_a1, f_a2, f_b1, f_b2)
        print 1
        sys.stdout.flush()

if __name__ == "__main__":
    main()
