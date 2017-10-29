import math
from copy import deepcopy

def wins(table, X):
    for i in xrange(3):
        if all(table[i][j] == X for j in xrange(3)):
            return True
        if all(table[j][i] == X for j in xrange(3)):
            return True
    if all(table[i][i] == X for i in xrange(3)):
        return True
    if all(table[i][2-i] == X for i in xrange(3)):
        return True
    return False


def BFS(moves, queue):
    while queue:
        my_moves, table = queue.pop(0)
        print my_moves
        # for row in table:
        #     print row
        # print
        if wins(table, 'X'):
            # for row in table:
            #     print row
            for i, j in my_moves:
                print i+1, j+1
            return
        for i in xrange(3):
            for j in xrange(3):
                if table[i][j] == '':
                    new_table = deepcopy(table)
                    new_table[i][j] = 'O'
                    if wins(new_table, 'O'):
                        continue
                    for k, l in moves:
                        if new_table[k-1][l-1] == '':
                            new_table[k-1][l-1] = 'X'
                            queue.append((my_moves+[(i, j)], new_table))
                            break
    return "Oops"


def solve():
    moves = [[int(i) for i in raw_input().split()] for j in range(9)]
    queue = []
    table = [[''] * 3 for _ in xrange(3)]
    table[moves[0][0]-1][moves[0][1]-1] = 'X'
    queue.append(([], table))
    s = BFS(moves, queue)
    if s == "Oops":
        print s


def main():
    solve()

if __name__ == "__main__":
    main()

