#include <cstdio>
#include <algorithm>

#define MAXN 1000

#define X first
#define Y second
#define mp make_pair
#define pb push_back

using namespace std;

typedef pair< int, int > pii;
typedef pair< pii, int > lion;

static int BIT[ 3001 ][ 3001 ][ 4 ];

void update( int x, int y, int w, int id )
{
    if( x == 0 || y == 0 ) return;
    while( x <= 3000 ) {
        int ny = y;
        while( ny <= 3000 ) {
            BIT[ x ][ ny ][ id ] += w;
            ny += ( ny & -ny );
        }
        x += ( x & -x );
    }
}

int query( int x, int y, int id )
{
    int ans = 0;
    if( x == 0 || y == 0 ) return 0;
    while( x > 0 ) {
        int ny = y;
        while( ny > 0 ) {
            ans += BIT[ x ][ ny ][ id ];
            ny -= ( ny & -ny );
        }
        x -= ( x & -x );
    }
    return ans;
}

void upd( int x1, int y1, int x2, int y2 ) {
        x1 = max( x1, 1 );
        y1 = max( y1, 1 );
        update(x1,y1,1,0);
            update(x1,y2+1,-1,0);
            update(x2+1,y1,-1,0);
            update(x2+1,y2+1,1,0);

            update(x1,y1,1*(1-y1),1);
            update(x1,y2+1,1*y2,1);
            update(x2+1,y1,1*(y1-1),1);
            update(x2+1,y2+1,-y2*1,1);

            update(x1,y1,1*(1-x1),2);
            update(x1,y2+1,1*(x1-1),2);
            update(x2+1,y1,1*x2,2);
            update(x2+1,y2+1,-x2*1,2);

            update(x1,y1,(x1-1)*(y1-1)*1,3);
            update(x1,y2+1,-y2*(x1-1)*1,3);
            update(x2+1,y1,-x2*(y1-1)*1,3);
            update(x2+1,y2+1,x2*y2*1,3);
}

int get_query( int x1, int y1, int x2, int y2 ) {
        x1 = max( x1, 1 );
        y1 = max( y1, 1 );
        int val1=query(x2,y2,0)*x2*y2+query(x2,y2,1)*x2+query(x2,y2,2)*y2+query(x2,y2,3);
            int val2=query(x2,y1-1,0)*x2*(y1-1)+query(x2,y1-1,1)*x2+query(x2,y1-1,2)*(y1-1)+query(x2,y1-1,3);
            int val3=query(x1-1,y2,0)*(x1-1)*y2+query(x1-1,y2,1)*(x1-1)+query(x1-1,y2,2)*y2+query(x1-1,y2,3);
            int val4=query(x1-1,y1-1,0)*(x1-1)*(y1-1)+query(x1-1,y1-1,1)*(x1-1)+query(x1-1,y1-1,2)*(y1-1)+query(x1-1,y1-1,3);
            int ans=val1-val2-val3+val4;
        return ans;
}

int readint() {
    int n = 0;
    char c = getchar_unlocked();
    while ( !( '0' <= c && c <= '9' ) ) {
        c = getchar_unlocked();
    }
    while ( '0' <= c && c <= '9' ) {
        n = n * 10 + c - '0';
        c = getchar_unlocked();
    }
    return n;
}

pii L[ 1000001 ];

int main( void ) {
    int N, M, K;
    N = readint();
    M = readint();
    K = readint();
    for( int i = 1; i <= K; i++ ) {
        int x, y, d;
        x = readint();
        y = readint();
        d = readint();
        int xx = x + y;
        int yy = x - y;
        yy += MAXN;
        int x1 = max( xx - d , 1 ), x2 = xx + d ;
        int y1 = max( yy - d , 1 ), y2 = yy + d;
        upd( x1, y1, x2, y2 );
        L[ i ] = mp( xx, yy );
    }
    int mx = 1, idx = 1;
    for( int i = 1; i <= K; i++ ) {
        int xx = L[ i ].X, yy = L[ i ].Y;
        int ans = get_query( xx, yy, xx, yy );
        if( ans > mx ) {
                mx = ans;
                idx = i;
        }
    }
    printf("%d %d\n", idx, mx - 1 );
    return 0;
}
