#include <stdio.h> 
#include <vector>
#include <utility>
#include <queue>
#include <string.h>
#include <map>
#include <math.h>

using namespace std;


int N;
int maxblackdepth;
int maxwhitedepth;

void printboard(int board[][11]) {
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
}

int abs(int x) {
	return x>0?x:-x;
}

void track(int originboard[][11], int x, int y, int depth, int black) {
	if (black) {
		if(maxblackdepth < depth) {
			maxblackdepth = depth;
		}
	}
	else {
		if(maxwhitedepth < depth) {
			maxwhitedepth = depth;
		}
	}

	
	int board[11][11];
	bool flag = false;
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			if (i+j == x+y || (i-j) == (x-y)) {
				board[i][j] = 0;
			}
			else {
				board[i][j] = originboard[i][j];
			}
			if (board[i][j] == 1){
				flag = true;
			}
		}
	}
	
	
	if (!flag) {
		return;
	}
	
	for(int i=x; i<N; i++) {
		for(int j=(i==x?y:0); j<N; j++) {
			if (board[i][j] != 0) {
				if ((i+j)%2==black) {
					track(board, i, j, depth+1, black);
				}
			}	
		}
	}
	
	
	
	return;
}



int main() {
	
	
	int board[11][11];
	scanf("%d", &N);
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	int x, y;
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			if (board[i][j] != 0) {
				if ((i+j)%2==0) {
					track(board, i, j, 1, 0);
				}
				else {
					track(board, i, j, 1, 1);
				}
				
			}	
		}
	}
	

	
	printf("%d", maxblackdepth + maxwhitedepth);
}
