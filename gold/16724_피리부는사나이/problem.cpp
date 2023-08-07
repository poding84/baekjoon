#include <stdio.h> 
#include <vector>
#include <utility>
#include <queue>
#include <string.h>
#include <map>
#include <math.h>

using namespace std;


char board[1010][1010];


bool visited[1010][1010];

pair<int, int> mom[1010][1010];


pair<int, int> getmom(pair<int, int> p){
	pair<int, int> s = {-1, -1};
	if (mom[p.first][p.second] == s) {
		return p;
	}
	else {
		pair<int, int>temp = getmom(mom[p.first][p.second]);
		mom[p.first][p.second] = temp;
		return temp;
	}
}

void comb(pair<int, int> p1, pair<int, int> p2) {
	if (getmom(p1) == getmom(p2)) {
		return;
	}
	
	mom[p1.first][p1.second] = p2;
	return;
}

void dfs(int x, int y) {
	if (visited[x][y]) {
		return;
	}
	visited[x][y] = true;
	
	switch(board[x][y]) {
		case 'U' :
			comb({x,y}, {x-1, y});
			dfs(x-1, y);
			break;
		case 'D' :
			comb({x,y}, {x+1, y});
			dfs(x+1, y);
			break;
		case 'L' :
			comb({x,y}, {x, y-1});
			dfs(x, y-1);
			break;
		case 'R' :
			comb({x,y}, {x, y+1});
			dfs(x, y+1);
			break;
	}
	
}


int main() {
	
	int N, M;
	int ans = 0;
	
	
	scanf("%d %d", &N, &M);
	
	for(int i=0; i<N; i++) {
		scanf("%s", board[i]);
		for(int j=0; j<M; j++) {
			mom[i][j] = {-1, -1};
		}
	}
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			if(!visited[i][j]) {
				dfs(i, j);
			}
		}
	}
	pair<int, int> deff = {-1, -1};
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			if (mom[i][j] == deff) {
				ans++;
			}
		}
	}
	printf("%d", ans);
}

