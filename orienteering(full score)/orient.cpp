#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>
#include <set>

#define MAXN 610
#define INF 1234567890123.0

#define X first
#define Y second
#define mp make_pair
#define pb push_back

using namespace std;

typedef pair< int, int > pii;
typedef pair< double, pii > node;

int N, M, P;
double R[ MAXN + 1 ][ MAXN + 1 ], H[ MAXN + 1 ][ MAXN + 1 ];

vector< pii > points;

double round( double num ) {
    return ceil(num*pow(10,6))/pow(10,6);
}
double W( int i, int j, int k, int l ) {
    return round( ( double )exp( 3.5*fabs( 0.05 + ( H[ k ][ l ] - H[ i ][ j ] ) / 10.0 ) ) *( R[ i ][ j ] + R[ k ][ l ] ) / 2.0 );
}

double dist[ MAXN + 1 ][ MAXN + 1 ];
set< node > Q;

void check( double d, int x1, int y1, int x2, int y2 ) {
    if( x2 > N || x2 <= 0 || y2 > M || y2 <= 0 ) return;
    double dd = d + W( x1, y1, x2, y2 );
    if( dd - dist[ x2 ][ y2 ] < 1e-6 ) {
        Q.insert( mp( dd, mp( x2, y2 ) ) );
        dist[ x2 ][ y2 ] = dd;
    }
}

double dijkstra( pii S, pii T ) {
    for( int i = 0; i <= MAXN; i++ ) {
        for( int j = 0; j <= MAXN; j++ ) {
            dist[ i ][ j ] = INF;
        }
    }
    dist[ S.X ][ S.Y ] = 0.0;
    Q.insert( mp( 0.0, S ) );
    while(!Q.empty()) {
        node A = *Q.begin();
        Q.erase( Q.begin() );
        int x = A.Y.X, y = A.Y.Y;
        double d = round( A.X );
        check( d, x, y, x + 1, y );
        check( d, x, y, x - 1, y );
        check( d, x, y, x, y + 1 );
        check( d, x, y, x, y - 1 );
    }
    return dist[ T.X ][ T.Y ];
}

int main( void ) {
    scanf("%d%d", &N, &M );
    scanf("%d", &P );
    P++;
    for( int i = 1; i <= P; i++ ) {
        int x, y;
        scanf("%d%d", &x, &y );
        x++, y++;
        points.pb( mp( x, y ) );
    }
    for( int i = 1; i <= N; i++ ) {
        for( int j = 1; j <= M; j++ ) {
            scanf("%lf", &R[ i ][ j ] );
        }
    }
    for( int i = 1; i <= N; i++ ) {
        for( int j = 1; j <= M; j++ ) {
            scanf("%lf", &H[ i ][ j ] );
        }
    }
    double ans = 0.0;
    for( int i = 0; i < P - 1; i++ ) {
        double cost = dijkstra( points[ i ], points[ i + 1 ] );
        ans += round( cost );
    }
    cout << ( int )( ans + 1 ) << endl;
    return 0;
}
