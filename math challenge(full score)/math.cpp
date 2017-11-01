#include <cstdio>
#include <algorithm>
#include <vector>

#define MOD 1000000007LLU

#define X first
#define Y second
#define mp make_pair
#define pb push_back

#define MAXN 3010

using namespace std;

typedef unsigned long long llu;

typedef pair< llu, llu > pii;

llu Binom[ MAXN + 1 ][ MAXN + 1 ];

llu fact( llu a ) {
    llu factorial = 1LLU;
    for( llu i = 1; i <= a; i++ ) factorial = ( factorial * i ) % ( MOD - 1LLU );
    return factorial;
}

llu power( llu a, llu b ) {
    if( b == 0 ) return 1LLU;
    else if( b == 1 ) return a;
    llu val = power( a, b / 2 ) % MOD;
    if( b % 2 ) return ( ( val * val ) % MOD ) * a % MOD;
    else return ( val * val ) % MOD;
}

pii extended_euclidean( llu a, llu b ) {
  if( b == 0llu ) return mp( 1llu, 0llu );
  pii A = extended_euclidean( b, a % b );
  return mp( A.Y, ( A.X - A.Y * ( a / b ) ) );
}

llu inverse( llu a, llu p ) {
  return ( extended_euclidean( a, p ).X + p ) % p;
}

void calc() {
    for( int i = 0; i <= MAXN; i++ ) Binom[ i ][ 0 ] =1;
    for( int i = 1; i <= MAXN; i++ ) {
        for( int j = 1; j <= i; j++ ) {
            Binom[ i ][ j ] = ( Binom[ i - 1 ][ j ] + Binom[ i - 1 ][ j - 1 ] ) % ( MOD - 1 );
        }
    }
}

int main( void ) {
    int T;
    calc();
    scanf("%d", &T ) ;
    for( int t = 1; t <= T; t++ ) {
        llu a, b, c;
        scanf("%llu%llu%llu", &a, &b, &c );
        llu binom;
        if( b <= 3000 && c <= 3000 ) {
            binom = Binom[ b ][ c ];
        }  else {
            binom = fact( b ) % ( ( MOD - 1LLU )  );
            binom = ( binom * inverse( fact( c ), ( MOD - 1LLU ) / 2LLU ) ) %  ( ( MOD - 1LLU )  );
            binom = ( binom * inverse( fact( b - c ), ( MOD - 1LLU ) / 2LLU ) ) % ( ( MOD - 1LLU ) );
        }
        printf("%llu\n", power( a, binom) );
    }
    return 0;
}
