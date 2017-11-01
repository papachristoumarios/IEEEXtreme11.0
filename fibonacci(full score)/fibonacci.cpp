#include <cstdio>
#include <algorithm>
#include <vector>

#define X first
#define Y second
#define mp make_pair
#define pb push_back

using namespace std;

typedef pair< int, int > pii;
typedef pair< pii, pii > table;

table product( table A, table B ) {
    int num1 = A.X.X * B.X.X + A.X.Y * B.X.Y;
    int num2 = A.X.X * B.Y.X + A.X.Y * B.Y.Y;
    int num3 = A.Y.X * B.X.X + A.Y.Y * B.X.Y;
    int num4 = A.Y.X * B.Y.X + A.Y.Y * B.Y.Y;
    num1 %= 10;
    num2 %= 10;
    num3 %= 10;
    num4 %= 10;
    return mp( mp( num1, num3 ), mp( num2, num4 ) );
}

table expo( table A, int v ) {
    if( v == 0 ) return mp( mp( 1, 0 ), mp( 0, 1 ) );
    if( v == 1 ) return A;

    table B = expo( A, v / 2 );
    if( v % 2 ) return product( product( B, B ), A );
    else return product( B, B );
}

int main( void ) {
    int T;
    scanf("%d", &T );
    while( T-- ) {
        int N;
        scanf("%d", &N );
        pii A = mp( 1, 0 );
        table B = mp( mp( 1, 1 ), mp( 1, 0 ) );
        B = expo( B, N );
        printf("%d\n", B.X.X );
    }
    return 0;
}
