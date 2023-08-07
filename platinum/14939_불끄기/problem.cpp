#include <stdio.h> 
#include <vector>
#include <utility>
#include <queue>
#include <string.h>
#include <map>
#include <math.h>
#include <set>



using namespace std;

char board[11][11];
char originboard[11][11];

void printboard(){
	for(int i=0; i<10; i++) {
		for(int j=0; j<10; j++) {
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
	printf("-------\n");
}

int pushnum = 0;

void copyboard() {
	pushnum = 0;
	for(int i=0; i<10; i++) {
		for(int j=0; j<10; j++) {
			board[i][j]=originboard[i][j];
		}
	}
}

int dir[5][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {0, 0}};



void convert(int x, int y) {
	if (!(0<=x && x<10)) {
		return;
	}
	
	if (!(0<=y && y<10)) {
		return;
	}
	
	if (board[x][y] == '#') {
		board[x][y] = 'O';
	}
	else {
		board[x][y] = '#';
	}
}

void push(int row, int column) {
	pushnum++;
	for(int i=0; i<5; i++) {
		int x, y;
		x = row + dir[i][0];
		y = column + dir[i][1];
		convert(x, y);
	}
}


void push_first_row(int index) {
	for(int i=0; i<10; i++) {
		int temp = 1<<i;
		if (index & temp) {
			push(0, i);
		}
	}
}

void push_row(int index) {
	for(int i=0; i<10; i++) {
		if (board[index-1][i] == 'O') {
			push(index, i);
		}
	}
}

int main() {
	
	for(int i=0; i<10; i++) {
		scanf("%s", originboard[i]);
	}
	
	int minpush = 10000;
	
	for(int i=0; i<1024; i++) {
		copyboard();
		push_first_row(i);
		//printboard();
		for(int j=1; j<10; j++) {
			push_row(j);
		}
		bool flag = true;
		for(int j=0; j<10; j++) {
			if (board[9][j] == 'O') {
				flag = false;
				break;
			}
		}
		if (flag) {
			if (minpush > pushnum) {
				minpush = pushnum;
			}
		}
	}
	
	if (minpush == 10000) {
		printf("-1");
	}
	else {
		printf("%d", minpush);
	}
	
	
}
