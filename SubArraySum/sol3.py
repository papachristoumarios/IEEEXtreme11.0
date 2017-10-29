import math
from itertools import product

def solve():
    D = int(input())
    d = [int(i) for i in input().split()]
    while len(d) < 5:
        d.append(1)
    d1 = [i+1 for i in d]
    p = 1
    for i in d1:
        p *= i
    old_arr = [int(i) for i in input().split()]
    arr = [[[[[0] * d[-1] for _ in range(d[-2])] for _ in range(d[-3])] for _ in range(d[-4])] for _ in range(d[-5])]
    C = 0
    for i in range(d[0]):
        for j in range(d[1]):
            for k in range(d[2]):
                for l in range(d[3]):
                    for m in range(d[4]):
                        arr[i][j][k][l][m] = old_arr[C]
                        C += 1
    sum_arr = [[[[[0] * d1[-1] for _ in range(d1[-2])] for _ in range(d1[-3])] for _ in range(d1[-4])] for _ in range(d1[-5])]
    for pos in product(*[range(1, x) for x in d1]):
        prev = [i-1 for i in pos]
        for diff in product(*zip(prev, pos)):
            # print "pos = {}, len(pos) = {}, diff = {}, len(diff) = {}".format(pos, len(pos), diff, len(diff))
            exp = sum(d != p for d, p in zip(diff, pos))
            if exp == 0:
                continue
            mul = 1 if exp & 1 else -1
            sum_arr[pos[0]][pos[1]][pos[2]][pos[3]][pos[4]] += mul * sum_arr[diff[0]][diff[1]][diff[2]][diff[3]][diff[4]]
        # print arr[prev[0]]
        sum_arr[pos[0]][pos[1]][pos[2]][pos[3]][pos[4]] += arr[prev[0]][prev[1]][prev[2]][prev[3]][prev[4]]
        # print sum_arr[pos[0]][pos[1]][pos[2]][pos[3]][pos[4]]
    # print sum_arr
    Q = int(input())
    for q in range(Q):
        start = [int(i)-1 for i in input().split()]
        end = [int(i) for i in input().split()]
        s = 0
        while len(start) < 5:
            start.append(0)
            end.append(1)
        for diff in product(*zip(start, end)):
            exp = sum(d != p for d, p in zip(diff, end)) & 1
            mult = -1 if exp else 1
            s += mult * sum_arr[diff[0]][diff[1]][diff[2]][diff[3]][diff[4]]
        print(s)




def main():
    solve()

if __name__ == "__main__":
    main()
