#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define pb push_back

using namespace std;

typedef pair< int, string > pii;

vector< pii > V;
vector< string > L[ 255 ];


int main( void ) {
    int N;
    scanf("%d", &N );
    for( int i = 0; i < N; i++ ) {
        string a;
        int b;
        cin >> a >> b;
        L[ b ].pb( a );
    }
    int val = 1;
    for( int i = 0; i < 255; i++ ) {
        if( !L[ i ].size() ) continue;
        sort( L[ i ].begin(), L[ i ].end() );
        for( int j = 0; j < L[ i ].size(); j++ ) {
            cout << L[ i ][ j ] << " ";
        }
        cout << val << " " <<  val + L[ i ].size() - 1 << endl;
        val += L[ i ].size();
    }
    return 0;
}
