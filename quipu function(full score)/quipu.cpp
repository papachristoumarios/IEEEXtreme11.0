#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;

int main( void ) {
    ll a, b;
    int q;
    scanf("%d%lld%lld", &q, &a, &b );
    for( int qq = 0; qq < q; qq++ ) {
        int d;
        scanf("%d", &d );
        ll result = 0;
        for( ll div = 1; div <= 1000000; div++ ) {
            ll first = ( a / ( ll )div ) * ( ll )div;
            if( first < a ) first += ( ll )div;
            while( first <= b ) {
                if( div % d ) result++;
                if( ( ll )div * ( ll )div != first && ( ( ll )first / div > 1000000 ) && ( ( first / div ) % d )  ) result++;
                first += ( ll )div;
            }
        }
        printf("%lld\n", result );
    }
    return 0;
}
