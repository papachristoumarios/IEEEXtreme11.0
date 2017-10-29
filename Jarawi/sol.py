import math
from bisect import bisect_right
from copy import deepcopy

a = ord('a')
letter_buckets = {chr(a+i): [] for i in range(26)}

def check_suffix(p):
    pointer = -1
    for letter in p:
        pos = bisect_right(letter_buckets[letter], pointer)
        if pos == len(letter_buckets[letter]):
            # print p, False
            return False
        pointer = letter_buckets[letter][pos]
    # print p, True
    return True

def solve():
    p = raw_input()
    left = 0
    right = len(p)
    while left <= right:
        middle = (left+right)/2
        flag = check_suffix(p[middle:])
        if flag:
            right = middle - 1
            ans = middle
        else:
            left = middle + 1
    print len(p) - ans
    return

def main():
    S = raw_input()
    for i, letter in enumerate(S):
        letter_buckets[letter].append(i)
    buckets = deepcopy(letter_buckets)
    for letter in letter_buckets.keys():
        pointers = {l: 0 for l in letter_buckets.keys()}
        for i in range(len(letter_buckets[letter])):
            for l in letter_buckets.keys():
                while (pointers[l] < len(letter_buckets[l])) and (letter_buckets[l][pointers[l]] <= letter_buckets[letter][i]):
                    pointers[l] += 1
            buckets[letter][i] = (letter_buckets[letter][i], deepcopy(pointers))
    print buckets['a']
    N = int(raw_input())
    for _ in xrange(N):
        solve()

if __name__ == "__main__":
    main()
