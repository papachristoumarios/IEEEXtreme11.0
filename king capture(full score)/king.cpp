#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

#define X first
#define Y second
#define mp make_pair
#define pb push_back

#define MAXN 155

using namespace std;

typedef pair< int, int > pii;

vector< int > G[ MAXN + 1 ];

int GetBlack() {
    int black_king_node;
    cin >> black_king_node;
    return black_king_node;
}

void SetWhite(int node) {
    cout << node << endl;
}

int N, M;

void ReadGraph() {
    cin >> N >> M;
    for (int i = 0; i < M; i += 1) {
        int a, b;
        cin >> a >> b;
        G[ a ].pb( b );
        G[ b ].pb( a );
    }
}

bool dp[ MAXN + 1 ][ MAXN + 1 ][ MAXN + 1 ][ 2 ];

void precompute() {
    for( int i = 1; i <= N; i++ ) {
        dp[ i ][ i ][ 0 ][ 0 ] = dp[ i ][ i ][ 0 ][ 1 ] = true;
    }
    for( int k = 1; k <= 150; k++ ) {
        for( int u = 1; u <= N; u++ ) {
            for( int v = 1; v <= N; v++ ) {
                // i am playing
                dp[ u ][ v ][ k ][ 0 ] = dp[ u ][ v ][ k - 1 ][ 1 ];
                for( int i = 0; i < G[ u ].size(); i++ ) {
                    int uu = G[ u ][ i ];
                    if( dp[ uu ][ v ][ k - 1 ][ 1 ] ) dp[ u ][ v ][ k ][ 0 ] = true;
                }
                // opponent is playing
                dp[ u ][ v ][ k ][ 1 ] = true;
                if( !dp[ u ][ v ][ k - 1 ][ 0 ] ) dp[ u ][ v ][ k ][ 1 ] = false;
                for( int i = 0; i < G[ v ].size(); i++ ) {
                    int vv = G[ v ][ i ];
                    if( !dp[ u ][ vv ][ k - 1 ][ 0 ] ) dp[ u ][ v ][ k ][ 1 ] = false;
                }
            }
        }
    }
}

int main() {
    ReadGraph();
    precompute();
    int node = 1, minimax = N;
    for( int i = 1; i <= N; i++ ) {
        int maxmoves = -1;
        for( int j = 1; j <= N; j++ ) {
            int move;
            for( int k = 0; k <= 150; k++ ) {
                if( dp[ i ][ j ][ k ][ 0 ] ) {
                    move = k;
                    break;
                }
            }
            if( move > maxmoves ) maxmoves = move;
        }
        if( minimax > maxmoves ) {
            node = i;
            minimax = maxmoves;
        }
    }
    SetWhite( node );
    fflush( stdin );
    int a = node, b = GetBlack(), k = minimax;
    while( true ) {
        for( int i = 0; i < G[ a ].size(); i++ ) {
            int u = G[ a ][ i ];
            if( dp[ u ][ b ][ k - 1 ][ 1 ] ) {
                a = u;
                break;
            }
        }
        SetWhite( a );
        fflush( stdin );
        k--;
        if( a == b ) break;
        b = GetBlack();
        if( a == b ) break;
        k--;
    }
    return 0;
}
