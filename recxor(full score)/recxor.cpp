#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

ll xx(ll n)
{
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0;
}

int main( void ) {
    int T;
    scanf("%d", &T );
    for( int t = 1; t <= T; t++ ) {
        ll l, h, n, d1, d2;
        scanf("%lld%lld%lld%lld%lld", &l, &h, &n, &d1, &d2 );
        ll first = xx( n + l* h - 1 ) ^ xx( n - 1 );
        ll second = 0;
        ll x1, y1, x2, y2;
        x1 = ( d1 - n ) / l + 1;
        y1 = (d1 - n + 1 ) - ( x1 - 1 ) * l;
        x2 = ( d2 - n ) / l + 1;
        y2 = ( d2 - n + 1 ) - ( x2 - 1 ) * l;
        if( x1 > x2 ) swap( x1, x2 );
        if( y1 > y2 ) swap( y1, y2 );

        for( int i = x1; i <= x2; i++ ) {
            ll left = n + y1 - 1 + ( i - 1 ) * l;
            ll right = n + y2 + ( i - 1 ) * l - 1;
            second ^= xx( right ) ^ xx( left - 1 );
        }
        ll res = first ^ second;
        printf("%lld\n", res );
    }
    return 0;
}
