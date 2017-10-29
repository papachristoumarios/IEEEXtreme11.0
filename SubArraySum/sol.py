import math
from itertools import product
import numpy as np

def solve():
    D = int(raw_input())
    d = np.array([int(i) for i in raw_input().split()], dtype=int)
    arr = np.array([int(i) for i in raw_input().split()], dtype=int).reshape(d)
    sum_arr = np.zeros(shape=d+1, dtype=int)
    for pos in product(*[range(1, x) for x in d+1]):
        prev = [i-1 for i in pos]
        for diff in product(*zip(prev, pos)):
            exp = sum(d != p for d, p in zip(diff, pos))
            if exp == 0:
                continue
            mul = 1 if exp & 1 else -1
            sum_arr[pos] += mul * sum_arr[diff]
        if D == 1:
            sum_arr[pos] += arr[prev]
        else:
            sum_arr[pos] += arr[zip(prev)]
    Q = int(raw_input())
    for q in xrange(Q):
        start = [int(i)-1 for i in raw_input().split()]
        end = [int(i) for i in raw_input().split()]
        s = 0
        mult = []
        other = []
        for diff in product(*zip(start, end)):
            exp = sum(d != p for d, p in zip(diff, end)) & 1
            mult.append(-1 if exp else 1)
            other.append(diff)
        if D == 1:
            s = (mult * sum_arr[[i[0] for i in other]]).sum()
        else:
            s = (mult * sum_arr[zip(*other)]).sum()
        print s




def main():
    solve()

if __name__ == "__main__":
    main()
