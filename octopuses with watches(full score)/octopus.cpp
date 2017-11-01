#include <cstdio>
#include <algorithm>
#include <vector>

#define MAXN 10

using namespace std;

int grid[ MAXN + 1 ][ MAXN + 1 ];

int main( void ) {
    int N, M;
    scanf("%d%d", &N, &M );
    for( int i = 0; i < N; i++ ) {
        for( int j = 0; j < M; j++ ) {
            scanf("%d", &grid[ i ][ j ] );
            grid[ i ][ j ] %= 3;
        }
    }

    int ans = 0, bound = 1;
    for( int i = 1; i <= M; i++ ) bound *= 3;
    for( int num = 0; num < bound; num++ ) {
        int res = 0;
        int grid2[ MAXN + 1 ][ MAXN + 1 ], add[ MAXN + 1 ];
        for( int i = 0; i < N; i++ ) {
            for( int j = 0; j < M; j++ ) {
                grid2[ i ][ j ] = grid[ i ][ j ];
            }
        }
        int num2 = num;
        for( int i = 0; i < M; i++ ) {
            add[ i ] = num2 % 3;
            num2 /= 3;
        }
        for( int j = 0; j < M; j++ ) {
            for( int i = 0; i < N; i++ ) {
                grid2[ i ][ j ] = ( grid2[ i ][ j ] + add[ j ] ) % 3;
            }
        }
        for( int i = 0; i < N; i++ ) {
            int cl[ 3 ] = { 0 };
            for( int j = 0; j < M; j++ ) {
                cl[ grid2[ i ][ j ] ]++;
            }
            res += max( max( cl[ 0 ], cl[ 1 ] ), cl[ 2 ] );
        }
        ans = max( ans, res );
    }
    printf("%d\n", ans );
    return 0;
}
