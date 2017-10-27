INF = 1000000

def cross_forest(H, r, c):
	global W
	DP = {}
	for i in range(r):
		for j in range(c):
			DP[i,j] = 0
	DP[0,0] = H
	for i in range(1, r ):
		DP[i, 0] = W[i][0] + DP[i-1, 0]
		if DP[i-1, 0] <= 0:
			DP[i,0] = - INF 
	for i in range(1, c):
		DP[0, i] = W[0][i] + DP[0, i-1]
		if DP[0, i-1] <= 0:
			DP[0, i] = - INF
	
	for i in range(1, r):
		for j in range(1, c):
			mx = max (DP[i-1, j], DP[i, j-1]) 
			if mx <= 0: DP[i,j] = - INF 
			else: DP[i,j] = mx + W[i][j]
	
	#print DP
	
	return DP[r - 1,c - 1]
	
r, c = map(int, raw_input().split())
W = [map(int, raw_input().split()) for j in range(c)]

lo, hi, ans = 1, 1000000, 1000000
while( lo <= hi ):
	mid = (lo + hi ) / 2
	if(cross_forest(mid,r,c) > 0 ):
		ans = mid
		hi = mid - 1
	else:
		lo = mid + 1

print ans 
	
	
	
	
	
