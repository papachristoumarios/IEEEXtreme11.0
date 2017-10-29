MOD = 1000000007

def fact(n):
    factorial = 1
    for i in range( 1, n + 1):
        factorial = ( factorial * i )
    return factorial

def power( a, b ):
    if b == 0:
        return 1
    if b == 1:
        return a
    val = power( a, b / 2 )
    if( b % 2 == 0 ):
        return ( val * val ) % MOD
    else:
        return ( val * val * a ) % MOD

t = int(raw_input())
for tt in range( 1, t + 1 ):
    a, b, c = map(int, raw_input().split() )
    binom = fact(b)/(fact(c)*fact(b-c)) % (MOD - 1 );
    print     power( a, binom )
