#include <stdio.h> 
#include <vector>
#include <utility>
#include <queue>
#include <string.h>
#include <map>


using namespace std;



int N;

int board[21][21];

int originboard[21][21];

void setboard() {
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			board[i][j]=originboard[i][j];
		}
	}
	return;
}

void printboard(){
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
	return;
}

int getmaxitem() {
	int m = -1;
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			if(board[i][j]>m) {
				m=board[i][j];
			}
		}
	}
	return m;
}

int dirarr[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

pair<int, int> nextele(int x,  int y, int dir) {
	return {x + dirarr[dir][0], y + dirarr[dir][1]};
}

pair<int, int> beforeele(int x,  int y, int dir) {
	return {x - dirarr[dir][0], y - dirarr[dir][1]};
}

int getendidx(pair<int, int> loc, int dir) {
	switch(dir) {
		case 0:
		case 1:
			return loc.second;
			break;
		case 2:
		case 3:
			return loc.first;
			break;
	}
}
int moveele(int idx, int loc, int dir) {
	pair<int, int> start;
	int startidx;
	
	pair<int, int> endele[4] = {{idx, 0}, {idx, N-1}, {0, idx}, {N-1, idx}};
	
	switch(dir) {
		case 0: //우 
			startidx = N-1;
			start = {idx, loc};
			break;
		case 1: //좌 
			start = {idx, loc};
			startidx = 0;
			break;
		case 2: //하 
			startidx = N-1;
			start = {loc, idx};
			break;
		case 3: //상 
			startidx = 0;
			start = {loc, idx};
			break;
		
	}
	int endidx = loc;
	
	for(pair<int, int> s = start; nextele(s.first, s.second, dir) != endele[dir] ; s = beforeele(s.first, s.second, dir)){
		
		if (loc == startidx && s == start) {
			continue;
		}
		
		if (board[s.first][s.second] == 0) {
			continue;
		}
		
		pair<int, int> before = nextele(s.first, s.second, dir);
		
//		printf("%d %d, %d %d\n", s.first, s.second, startidx, endidx);
//		printf("%d %d,\n", before.first, before.second);
//		printboard();
		if(board[s.first][s.second] == board[before.first][before.second]) {
			endidx = getendidx(beforeele(s.first, s.second, dir), dir);
			board[before.first][before.second] *= 2;
			board[s.first][s.second] = 0;
			continue;
		}
		
		if (board[before.first][before.second] == 0) {
			board[before.first][before.second] = board[s.first][s.second];
			board[s.first][s.second] = 0;
			continue;
		}
		
	}
	
	return endidx;
}

void moveboard(int dir) {
	pair<bool, int> isfrontmoved = {false, -1};
	switch(dir) {
		case 0: //우; 
			for(int i=0; i<N; i++) { //i번째 가로줄을 옮김; 
				
				for(int j=N-1, k=0; j>=0 && k<N; k++) {
					j = moveele(i, j, dir);
				}
			} 
			
			
			break;
		case 1: //좌 
			for(int i=0; i<N; i++) { //i번째 가로줄을 옮김; 
				
				for(int j=0, k=0; j<N && k<N; k++) {
					j = moveele(i, j, dir);
				}
			}
			break;
		case 2: //하 
			for(int i=0; i<N; i++) { //i번째 가로줄을 옮김; 
				for(int j=N-1, k=0; j>=0 && k<N; k++) {
					j = moveele(i, j, dir);
				}
			} 
			break;
		case 3: //상 
			for(int i=0; i<N; i++) { //i번째 가로줄을 옮김; 
				
				for(int j=0, k=0; j<N && k < N; k++) {
					j = moveele(i, j, dir);
				}
			} 
			break;
		
	}
}

int getmax(int dirs) {
	setboard();
	
	for(int i=0; i<5; i++) {
		int dir = dirs%4;
		
		moveboard(dir);
		
		
		dirs/=4;
	}
	
	return getmaxitem();
	
	
}


int main() {
	
	scanf("%d", &N);
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			scanf("%d", &originboard[i][j]);
		}
	}
	
	int mm = -1;
	for(int i=0; i<1<<10; i++) {
		int m = getmax(i);
		if (m > mm) {
			mm = m;
		}
	}
	
	printf("%d", mm);
	
	 
}
