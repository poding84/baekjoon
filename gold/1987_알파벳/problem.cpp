#include <stdio.h> 
#include <vector>
#include <utility>
#include <queue>
#include <string.h>
#include <map>
#include <math.h>
#include <stack>


using namespace std;


char board[32][32];


bool alphaVisited[30];
bool boardVisited[22][22];

int maxnum;
int curi;
int r, c;

int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int max(int x, int y) {
	return x>y ? x : y;
}


void dfs(int x, int y) {
	
	int alpha = board[x][y] - 'A';
	if (alphaVisited[alpha] || boardVisited[x][y]) {
		maxnum = max(maxnum, curi);
		return;
	}
	
	alphaVisited[alpha] = true;
	boardVisited[x][y] = true;
	
	curi++;
	for(int i=0; i<4; i++) {
		int nextx = x + dir[i][0];
		int nexty = y + dir[i][1];
		if ((0 <= nextx && nextx < r) && (0 <= nexty && nexty < c)) {
			dfs(nextx, nexty);
		}
	}
	
	curi--;
	alphaVisited[alpha] = false;
	boardVisited[x][y] = false;
	
	return;
	
}


int main() {
	
	
	
	scanf("%d %d", &r, &c);
	
	for(int i=0; i<r; i++) {
		scanf("%s", board[i]);
	}
	
	dfs(0, 0);
	
	printf("%d", maxnum);
	
	
}
