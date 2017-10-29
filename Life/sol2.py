n, m, c = map(int, raw_input().split())

def wrapped_index(index, size):
    if index < 0:
        return size -1
    if index >= size:
        return 0
    else:
        return index

grid = []
for i in range(n):
    grid.append(list(raw_input().strip()))

start, period, final = 0, 0, -1
hashmap = {}
for rnd in range(c):
    # Evolve
    new_grid = [g[:] for g in grid]
    s = []
    #for line in new_grid:
    #    print line
    #print
    for i in range(n):
        for j in range(m):
            x, y = i, j
            alive = 0
            allX = [wrapped_index(x-1, n), x, wrapped_index(x+1, n)]
            allY = [wrapped_index(y-1, m), y, wrapped_index(y+1, m)]

            for k in allX:
                for l in allY:
                    if (k != x or l != y) and grid[k][l] == '*':
                        alive += 1

            #print 'Cell {} {} has {} alive'.format(i,j, alive)
            if (grid[i][j] == '*') and (alive not in [2, 3]):
                new_grid[i][j] = '-'
            elif (grid[i][j] == '-') and (alive == 3):
                new_grid[i][j] = '*'
            s.append(new_grid[i][j])
    s = ''.join(s)
    grid = new_grid
    if rnd == final:
        break
    if (final==-1) and (s in hashmap):
        start = hashmap[s]
        period = rnd - start
        final = (c - rnd - 1) % period + rnd
        # break
    elif (final == -1) and (s not in hashmap):
        hashmap[s] = rnd


for i in range(n):
    print ''.join(grid[i])

