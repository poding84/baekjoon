#include <stdio.h> 
#include <vector>
#include <utility>
#include <queue>
#include <string.h>
#include <map>
#include <math.h>

using namespace std;

int board[1010][1010];
int ans[1010][1010];
int moms[1010][1010];
int realans[1010][1010];
int n, m;
	
void printboard() {
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			printf("%d", realans[i][j]%10);
		}
		printf("\n");
	}
	
}

void print() {
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			printf("%d", ans[i][j]);
		}
		printf("\n");
	}
	
}

void printmom() {
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			printf("%d", moms[i][j]);
		}
		printf("\n");
	}
	
}


int dirarr[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

bool visited[1010][1010];

int getval(int x, int y) {
	int mom = moms[x][y];
	int momx = (mom-1)/m;
	int momy = (mom-1)%m;
	
	return ans[momx][momy];
}

void dfs(int x, int y, int mom) {
	
	
	visited[x][y] = true;
	moms[x][y] = mom;
	ans[(mom-1)/m][(mom-1)%m]++;
	
	for(int i=0; i<4; i++) {
		int nextx = x + dirarr[i][0];
		int nexty = y + dirarr[i][1];
		
		if (0 <= nextx && nextx < n) {
			if (0 <= nexty && nexty < m) {
				
				if (!visited[nextx][nexty] && board[nextx][nexty] != 1) {
					dfs(nextx, nexty, mom);
				}
				
			}
		}
		
	}
	
	
}


int main() {
	

	scanf("%d %d", &n, &m);
	
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			scanf("%1d", &board[i][j]);
		}
	}
	
	

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if (board[i][j] == 0 && !visited[i][j]) {
				dfs(i, j, i*m+j + 1);
			}
		}
	}
	vector<int> v;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if (board[i][j] == 1) {
				realans[i][j] = 1;
				v.clear();
				for(int k = 0; k<4; k++) {
					int nextx = i + dirarr[k][0];
					int nexty = j + dirarr[k][1];
					
					if (0 <= nextx && nextx < n) {
						if (0 <= nexty && nexty < m) {
							bool flag = true;
							for(int t = 0; t<v.size(); t++) {
								if (moms[nextx][nexty] == v[t]) {
									flag = false;
									break;
								}
							}
							if (flag) {
								realans[i][j] += getval(nextx, nexty);
								v.push_back(moms[nextx][nexty]);
							}
							
							
						}
					}
				}
			}
		}
	}
	
	printboard();
//	printf("-------\n");
//	print();
//	printf("-----\n");
//	printmom();
	
}
