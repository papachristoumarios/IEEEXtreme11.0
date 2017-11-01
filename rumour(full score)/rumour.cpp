#include <cstdio>
#include <algorithm>

using namespace std;

typedef unsigned long long llu;

int main( void ) {
    int Q;
    scanf("%d", &Q );
    while( Q-- ) {
        llu u, v;
        scanf("%llu%llu", &u, &v );
        int ans = 0;
        llu uu = u, vv = v;
        int depth1 = 0, depth2 = 0;
        while( uu > 0 ) {
            depth1++;
            uu /= 2LLU;
        }
        while( vv > 0 ) {
            depth2++;
            vv /= 2LLU;
        }
        if( depth1 > depth2 ) {
            swap( u, v );
            swap( depth1, depth2 );
        }
        v /= ( llu )( 1 << ( llu )( depth2 - depth1 ) );
        ans += depth2 - depth1;
        while( u != v ) {
            u /= 2LLU;
            v /= 2LLU;
            ans += 2;
        }
        printf("%d\n", ans);
    }
    return 0;
}
