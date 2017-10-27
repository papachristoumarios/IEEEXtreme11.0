n, m, c = map(int, raw_input().split())

def hash_():
	b = '0b'
	for i in range(n):
		for j in range(m):
			if grid[i][j] == '-':
				b += '0'	
			elif grid[i][j] == '*':
				b += '1'
	return int(b , 2) % 999983 
	

def wrapped_index(index, size):
	if index < 0:
		return size -1 
	if index >= size:
		return 0
	else:
		return index

first_time = -1
grid = []
for i in range(n):
	grid.append(list(raw_input().strip('\n')))


h, h_inv = {}, {}

period = 0


for rnd in range(c):
	# Evolve
	to_be, not_to_be = [], []
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
			if grid[i][j] == '*': 
				if alive in [2,3]:
					to_be.append((i,j))
				else:
					not_to_be.append((i,j))
				
			elif alive == 3:
				to_be.append((i,j))
			else:
				not_to_be.append((i,j))
				
					
	for i,j in to_be:
		grid[i][j] = '*'
	for i,j in not_to_be:
		grid[i][j] = '-'
		
	if hash_() in h.keys():
		if first_time == -1:
			first_time = rnd
		else:
			period = rnd - first_time
			
			rem = (c - first_time) % period 
			grid = h_inv[rem]
			break
	else:
		h[hash_()] = rnd
		h_inv[rnd] = grid
		print h
		print h_inv
	
		
for i in range(n):
	print ''.join(grid[i])
	
	
			
			
			
	
	
