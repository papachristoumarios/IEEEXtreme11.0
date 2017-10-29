import math

def binom(i, j):
    return math.factorial(i)/(math.factorial(j)*math.factorial(i-j))

def solve(S):
    max_levels = int(math.floor(math.log(S, 2)))
    for k in xrange(1, max_levels):
        arr = [[0]*(S-2**(k-1)+1) for _ in xrange(k+1)]
        for i in xrange(k):
            b = binom(k, i)
            for s in xrange(S-2**(k-1)+1):
                arr[i][s] +=



def main():
    N = int(raw_input())
    solve(N)

if __name__ == "__main__":
    main()
