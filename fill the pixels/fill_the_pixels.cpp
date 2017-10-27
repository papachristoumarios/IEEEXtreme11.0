#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

#define MAXW 1000
#define pii pair < int , int > 
#define mp make_pair


char A [ MAXW + 1] [MAXW + 1];
bool visited [ MAXW + 1] [ MAXW + 1];

vector<pii> get_neighbours(int N, int M, int i, int j, char symbol) {
	
	if (symbol == '+') {
		vector<pii> neigh;
		neigh.push_back(mp(i-1, j));
		neigh.push_back(mp(i, j-1));
		neigh.push_back(mp(i+1, j));
		neigh.push_back(mp(i, j + 1));
		
		vector<pii> ret;
		
		for (pii n : ret) {
			int k = n.first;
			int l = n.second;
			if (k >= 0 && k < N && l >= 0 && l < M) ret.push_back(n);
			
		}
		return ret;
	}
	
	else if (symbol == 'x') {
		vector<pii> neigh;
		neigh.push_back(mp(i-1, j-1));
		neigh.push_back(mp(i+1, j-1));
		neigh.push_back(mp(i+1, j+1));
		neigh.push_back(mp(i-1, j+1));
		
		vector<pii> ret;
		
		for (pii n : ret) {
			int k = n.first;
			int l = n.second;
			if (k >= 0 && k < N && l >= 0 && l < M) ret.push_back(n);
			
		}
		return ret;	
			
	} 
	
	else {
		vector<pii> n1;
		vector<pii> n2;
		n1 = get_neighbours(N, M, i, j, '+');
		n2 = get_neighbours(N, M, i, j, 'x');
		
		for (pii n : n2) n1.push_back(n);
		return n1;
		
	}
	
	
}

void solve() {
	int M, N;
	cin >> M >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
			visited[i][j] = false;
		}	
			
	vector<pii> nn;
	nn = get_neighbours(N, M, N / 2, M / 2, '+');
	for (pii n : nn) {
		cout << n.first << " " << n.second << endl;
	}		
			
	char symbols[3] = { '+', 'x', '-' };
					
	int total;
	for (char symbol : symbols) {
		total = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (visited[i][j] || A[i][j] == '0') {
					continue;
				}
				queue<pii> q;
				q.push(mp(i,j));
				while (!q.empty()) {
					pii current = q.front();
					q.pop();
					int x = current.first;
					int y = current.second;
					vector<pii> neigh;
					neigh = get_neighbours(N, M, x, y, symbol);
					for (pii n : neigh) {
						int k = n.first;
						int l = n.second;
						if (!visited[k][l]) {
						q.push(n); visited[k][l] = true;	
					}
					}	
				}
				total++;
			}
				
		}
		printf("%d ", total);
	}		
}
int main(void) {
	int T; 
	cin >> T;
	while (T--) solve();
}
