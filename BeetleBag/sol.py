import math

def solve():
    C, G = [int(i) for i in raw_input().split()]
    gadgets = [[int(i) for i in raw_input().split()] for _ in xrange(G)]
    sol = [[0] * (C+1) for _ in xrange(G+1)]
    for i in xrange(1, G+1):
        for j in xrange(1, C+1):
            new_j = j - gadgets[i-1][0]
            if new_j < 0:
                sol[i][j] = sol[i-1][j]
                continue
            sol[i][j] = max(sol[i-1][j], gadgets[i-1][1]+sol[i-1][new_j])
    print sol[-1][-1]


def main():
    N = int(raw_input())
    for _ in xrange(N):
        solve()

if __name__ == "__main__":
    main()
