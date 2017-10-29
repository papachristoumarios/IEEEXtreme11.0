import math


def solve(A, prev, l, r):
    if prev[r] < l:
        return 0
    new_l = prev[r]
    left = new_l + 1
    right = r
    ans = new_l + 1
    while left <= right:
        middle = left + (right - left)/2
        if A[middle] > A[new_l]:
            left = middle + 1
            ans = middle
        else:
            right = middle - 1
    # print A[new_l+1:r+1], A[new_l], new_l, ans
    ret = r - new_l + 1
    if (ret % 2 == 0) and (ans != (new_l + r + 1)/2):
        return ret - 1
    else:
        return ret

def main():
    N = int(raw_input())
    A = [int(i) for i in raw_input().split()]
    p = [-1]
    prev = -1
    for i in xrange(1, N):
        if A[i-1] < A[i]:
            prev = i-1
        p.append(prev)
    # print A
    # print p
    Q = int(raw_input())
    for _ in xrange(Q):
        l, r = [int(i) for i in raw_input().split()]
        print solve(A, p, l-1, r-1)

if __name__ == "__main__":
    main()
