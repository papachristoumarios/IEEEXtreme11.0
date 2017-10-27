import math as m

to_polar = lambda r, theta : (r*m.cos(theta), r*m.sin(theta))
dist = lambda (x1,y1), (x2, y2) : m.sqrt((x1 - x2)*(x1 - x2) + (y1- y2)*(y1-y2))

r = float(raw_input())

coords = {0 : (0,0)}

for i in range(26):
	letter, theta = raw_input().split()
	theta = m.radians(float(theta))
	x, y = to_polar(r, theta)
	coords[letter] = (x,y)

D = {}
A = ord('A')
Z = ord('Z')
for letter1 in coords.keys():
	for letter2 in coords.keys(): 
		D[letter1, letter2] = dist(coords[letter1], coords[letter2])
		
S = raw_input().strip().upper()
total = 0
prev_pos = 0
for letter in S:
	if A <= ord(letter) <= Z:
		total += D[prev_pos, letter]
		prev_pos = letter

print int(m.ceil(total)) 
