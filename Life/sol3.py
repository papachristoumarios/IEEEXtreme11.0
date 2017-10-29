
n, m, c = map(int, input().split())

def wrapped_index(index, size):
    if index < 0:
        return size -1
    if index >= size:
        return 0
    else:
        return index

def tr(i, j):
    return i * m + j

def pprint(a):
    for i in range(n):
        print(a[i*m:(i+1)*m])
    print()

s = ''.join(input().strip() for _ in range(n))

start, period = 0, 0
hashmap = {}
tables = []
for rnd in range(c):
    # Evolve
    s2 = ''
    # pprint(s)
    for i in range(n):
        for j in range(m):
            x, y = i, j
            alive = 0
            allX = [wrapped_index(x-1, n), x, wrapped_index(x+1, n)]
            allY = [wrapped_index(y-1, m), y, wrapped_index(y+1, m)]
            for k in allX:
                for l in allY:
                    if ((k != x) or (l != y)) and (s[tr(k, l)] == '*'):
                        alive += 1
            # print i, j, alive

            #print 'Cell {} {} has {} alive'.format(i,j, alive)
            if (s[tr(i, j)] == '*'):
                if (alive in [2, 3]):
                    s2 += '*'
                else:
                    s2 += '-'
            elif (s[tr(i, j)] == '-'):
                if (alive == 3):
                    s2 += '*'
                else:
                    s2 += '-'
    s = s2
    # pprint(s)
    grid = [s[i*m:(i+1)*m] for i in range(n)]
    if s not in hashmap:
        hashmap[s] = rnd
        tables.append(s)
    else:
        start = hashmap[s]
        period = rnd - start
        final = (c - rnd - 1) % period
        s = tables[start+final]
        break

for i in range(n):
    print(s[i*m:(i+1)*m])

