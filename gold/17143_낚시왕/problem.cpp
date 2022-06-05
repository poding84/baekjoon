#include <stdio.h> 
#include <vector>
#include <utility>
#include <queue>
#include <string.h>
#include <map>
#include <math.h>

using namespace std;


int board[111][111];
int N, M, S;

vector<pair<pair<int, int>, int> > shark; //speed, direction, size

int ans;

int abs(int x) {
	return x>0?x:-x;
}


void eat(int x) {
	for(int i=1; i<=N; i++) {
		if (board[i][x] != 0) {
			ans += shark[board[i][x]].second;
			board[i][x] = 0;
			break;
		}
	}
}

int dirarr[5][2] = {{0, 0}, {-1,0}, {1,0}, {0,1}, {0,-1}};
int dirsimp[5] = {0, -1, 1, 1, -1};
 
int changedir(int dir) {
	switch(dir) {
		case 1:
			return 2;
		case 2 :
			return 1;
		case 3:
			return 4;
		case 4:
			return 3;
	}
}

pair<int, int> getnextpos(int x, int y, int sharkidx) {
	int speed = shark[sharkidx].first.first;
	int dir = shark[sharkidx].first.second; //1 : up 2 : down 3 : right 4 : left;
	int curr, mod;
	switch(dir) {
		case 1:
			curr = x;
			mod = N-1;
			break;
		case 2:
			curr = x;
			mod = N-1;
			break;
		case 3:
			curr = y;
			mod = M-1;
			break;
		case 4:
			curr = y;
			mod = M-1;
			break;
	}
	
	// speed = (2 * mod) * q + r; q만큼 머리를 흔들고, r만큼 진행 
	
	int r = speed%(2*mod);
	
	mod += 1;
	curr += r * dirsimp[dir];
	
	if(curr > mod) {
		curr = mod - (curr - mod);
		dir = changedir(dir);
		if (curr < 1) {
			curr = 1 + (1 - curr);
			dir = changedir(dir);
		}
	}
	else if (curr < 1) {
		curr = 1 + (1 - curr);
		dir = changedir(dir);
		if(curr > mod) {
			curr = mod - (curr - mod);
			dir = changedir(dir);
		}
	}
	
	shark[sharkidx].first.second = dir;
	
	if (dir <= 2) {
		return {curr, y};
	}
	else {
		return {x, curr};
	}
}

void moveshark() {
	int newboard[111][111];
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			newboard[i][j] = 0;
		}
	}
	
	
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			if (board[i][j] != 0) {
				pair<int, int> nextpos = getnextpos(i, j, board[i][j]);
				if (newboard[nextpos.first][nextpos.second] != 0) {
					
					int sizea = shark[board[i][j]].second;
					int sizeb = shark[newboard[nextpos.first][nextpos.second]].second;
					if (sizea>sizeb) {
						newboard[nextpos.first][nextpos.second] = board[i][j];
					}
				}
				else {
					newboard[nextpos.first][nextpos.second] = board[i][j];
				}
			}
		}
	}
	
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			board[i][j] = newboard[i][j];
		}
	}
}



void printshark() {
	printf("-----------\n");
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			printf("%2d", board[i][j]);
		}
		printf("\n");
	} 
}


int main() {

	scanf("%d %d %d", &N, &M, &S);
	
	shark.push_back({{-1, -1}, -1});
	
	for(int i=1; i<=S; i++) {
		int a, b, c, d, e;
		
		scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
		
		board[a][b]=i;
		shark.push_back({{c,d}, e});
		
	}
	for(int i=1; i<=M; i++) {
		eat(i);
		moveshark();
	}
	
	printf("%d", ans);
	
	
	
}
