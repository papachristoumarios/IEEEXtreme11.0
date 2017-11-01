#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
#include <iostream>
#include <sstream>

#define MAXN 500

using namespace std;

int visited[ MAXN + 1 ], par[ MAXN + 1 ], flow[ MAXN + 1 ][ MAXN + 1 ], cap[ MAXN + 1 ][ MAXN + 1 ];

bool bfs( int s, int t ) {
  memset( par, 0, sizeof( par ) );
  memset( visited, 0, sizeof( visited ) );
  queue< int > Q;
  Q.push( s );
  visited[ s ] = true;
  par[ s ] = -1;
  while( !Q.empty() ) {
    int u = Q.front();
    Q.pop();
    for( int i = 0; i < MAXN; i++ ) {
      if( !visited[ i ] && cap[ u ][ i ] - flow[ u ][ i ] > 0 ) {
        visited[ i ] = true;
        par[ i ] = u;
        Q.push( i );
      }
    }
  }
  return visited[ t ];
}

int maxflow( int s, int t ) {
  int ans = 0;
  while( bfs( s, t ) ) {
    int aug = 250;
    for( int i = t; i != s; i = par[ i ] ) {
      aug = min( aug, cap[ par[ i ] ][ i ] - flow[ par[ i ] ][ i ] );
    }
    ans += aug;
    for( int i = t; i != s; i = par[ i ] ) {
      flow[ par[ i ] ][ i ] += aug;
      flow[ i ][ par[ i ] ] -= aug;
    }
  }
  return ans;
}

int main( void ) {
    int N, x, y;
    scanf("%d\n", &N );
    for( int i = 1; i <= N; i++ ) {
        int y;
        for( int j = 1; j <= N; j++ ) cap[ i ][ j + 205 ] = 1;
        cap[ i ][ i + 205 ] = 0;
        int enterNumber;
        std::string line;
        getline(std::cin, line);
        std::istringstream iss(line);
        while (iss >> enterNumber)
        {
            cap[ i ][ enterNumber + 1 + 205 ] = 0;
        }
    }
    for( int i = 0; i < 205; i++ ) {
      cap[ 420 ][ i ] = 1;
      cap[ i + 205 ][ 421 ] = 1;
    }
    printf("%d\n", N - maxflow( 420, 421 ) );
    memset( flow, 0, sizeof( flow ) );
    memset( cap, 0, sizeof( cap ) );
  return 0;
}
