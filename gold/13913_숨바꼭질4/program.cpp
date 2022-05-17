#include <stdio.h>
#include <vector>
#include <utility>
#include <queue>

using namespace std;


int N, M;
int map[70][70];
int totvirus;
int totempty;

vector<pair<int, int> > emptys;
vector<pair<int, int> > virus;

int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};


void updateMap (pair<int, int> a, pair<int, int> b, pair<int, int> c) {
	map[a.first][a.second] = 1;
	map[b.first][b.second] = 1;
	map[c.first][c.second] = 1;
}

void reupdateMap (pair<int, int> a, pair<int, int> b, pair<int, int> c) {
	map[a.first][a.second] = 0;
	map[b.first][b.second] = 0;
	map[c.first][c.second] = 0;
}


int getEmptyArea(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
	updateMap(a, b, c);
	
	
	int checkerArr[70][70] = {0};
	int area = 0;
	
	for(int i=0; i<totvirus; i++) {
		int currvirus_x = virus[i].first;
		int currvirus_y = virus[i].second;
		
		if (checkerArr[currvirus_x][currvirus_y] == 1) {
			continue;
		}
		
		queue<pair<int, int> > q;
		q.push(virus[i]);
		while(!q.empty()) {
			int curr_x = q.front().first;
			int curr_y = q.front().second;
			q.pop();
			
			if (!( (0 <= curr_x && curr_x < N) && (0 <= curr_y && curr_y < M) )) {
				continue;
			}
			
			if (checkerArr[curr_x][curr_y] == 1) {
				continue;
			}
			
			
			
			if (map[curr_x][curr_y] == 1) {
				continue;
			}
			
			//printf("%d %d\n", curr_x, curr_y);
			checkerArr[curr_x][curr_y] = 1;
			area += 1;
			for(int j=0; j<4; j++) {
				int next_x = curr_x + dir[j][0];
				int next_y = curr_y + dir[j][1];
				
				q.push(make_pair(next_x, next_y));
				
			}
			
			
		}
		
		
		
	}
	
	
	reupdateMap(a, b, c);
	
	return totempty - 3 - area + totvirus;
}


int main() {
	scanf("%d %d", &N, &M);
	
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			scanf("%d", &map[i][j]);
			if(map[i][j] == 0) {
				emptys.push_back(make_pair(i, j));
				totempty += 1;
			}
			else if(map[i][j] == 2) {
				virus.push_back(make_pair(i, j));
				totvirus += 1;
			}
		}
	}
//	
//	int i, j, k;
//	i = 0;
//	j = 4;
//	k = 16;
//	int curr = getEmptyArea(empty[i], empty[j], empty[k]);
//	printf("%d %d %d | %d\n", i, j, k, curr);
//	return 0;

	int totempty = emptys.size();
	int max = -1;
	for(int i=0; i<totempty-2; i++) {
		for(int j=i+1; j<totempty-1; j++) {
			for(int k=j+1; k<totempty; k++) {
				int curr = getEmptyArea(emptys[i], emptys[j], emptys[k]);
				if (curr > max) {
					max = curr;
					//printf("%d %d %d | %d\n", i, j, k, curr);
				}
			}
		}
	}
	
	printf("%d", max);
	
	
	return 0;
	
}