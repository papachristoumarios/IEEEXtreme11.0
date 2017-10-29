import math
from bisect import bisect_right

a = ord('a')
letter_buckets = {chr(a+i): [] for i in range(26)}

def check_suffix(p):
    pointer = -1
    for letter in p:
        pos = bisect_right(letter_buckets[letter], pointer)
        if pos == len(letter_buckets[letter]):
            # print p, False
            return False
        new_pointer = letter_buckets[letter][pos]
        if new_pointer <= pointer:
            raise ValueError("You done fucked up")
        pointer = new_pointer
    # print p, True
    return True

def solve():
    p = input()
    left = 0
    right = len(p)
    while left <= right:
        middle = (left+right)//2
        flag = check_suffix(p[middle:])
        if flag:
            right = middle - 1
            ans = middle
        else:
            left = middle + 1
    print(len(p) - ans)
    return

def main():
    S = input()
    for i, letter in enumerate(S):
        letter_buckets[letter].append(i)
    N = int(input())
    for _ in range(N):
        solve()

if __name__ == "__main__":
    main()
