#include <cstdio>
#include <algorithm>

#define MAXN 250
#define INF 1234567

using namespace std;

int R, C, W[ MAXN + 1][ MAXN + 1], dp[ MAXN + 1][ MAXN + 1 ];

int valid( int H ){
    dp[ 1 ][ 1 ] = H;
    for( int i = 2; i <= R; i++ ) {
        dp[ i ][ 1 ] = dp[ i - 1 ][ 1 ] + W[ i ][ 1 ];
        if( dp[ i - 1 ][ 1 ] <= 0 ) dp[ i ][ 1 ] = -INF;
    }
    for( int i = 2; i <= C; i++ ) {
        dp[ 1 ][ i ] = dp[ 1 ][ i - 1 ] + W[ 1 ][ i ];
        if( dp[ 1 ][ i - 1 ] <= 0 ) dp[ 1 ][ i ] = -INF;
    }
    for( int i = 2; i <= R; i++ ) {
        for( int j = 2; j <= C; j++ ) {
            dp[ i ][ j ] = max( dp[ i - 1][ j ], dp[ i ][ j - 1 ] ) + W[ i ][ j];
            if( max( dp[ i - 1] [ j ], dp[ i ][ j - 1 ] ) <= 0 ) dp[ i ][ j ] = -INF;
        }
    }
    return dp[ R ][ C ] > 0;
}

int main( void ) {
    scanf("%d%d", &R, &C);
    for( int i = 1; i <= R; i++ ) {
        for( int j = 1; j <= C; j++ ) {
            scanf("%d", &W[ i ][ j ] );
        }
    }
    int lo = 1, hi = INF, ans = INF;
    while( lo <= hi ) {
        int mid = ( lo + hi ) / 2;
        if( valid( mid ) ) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    printf("%d\n", ans );
    return 0;
}
