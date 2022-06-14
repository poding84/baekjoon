#include <stdio.h> 
#include <vector>
#include <utility>
#include <queue>
#include <string.h>
#include <map>
#include <math.h>

using namespace std;

int power[100010][5][5];


int dist(int x,  int y) {
	if (x == y) {
		return 1;
	}
	if (x > y) {
		return dist(y, x);
	}
	
	if ( x == 0) {
		return 2;
	}
	if ( y-x == 1) {
		return 3;
	}
	if( y-x == 2) {
		return 4;
	}
	if (y-x == 3) {
		return 3;
	}
}

void printpower(int idx) {
	for(int i=0; i<5; i++) {
			for(int j=0; j<5; j++) {
				printf("%d ", power[idx][i][j]);
				
			}
			printf("\n");
		}
}

int min(int a, int b) {
	if (!a) return b;
	return a>b?b:a;
}

int main() {
	int idx = 0;
	while(true) {
		int a;
		scanf("%d", &a);
		if (a == 0) {
			break;
		}
		if (idx == 0) {
			power[0][0][a] = dist(0, a);
			power[0][a][0] = dist(a, 0);
			idx++;
			continue;
		}
		
		for(int i=0; i<5; i++) {
			for(int j=0; j<5; j++) {
				if (!power[idx-1][i][j]) continue;
				
				if (i != a) {
					power[idx][i][a] = min(power[idx][i][a], power[idx-1][i][j] + dist(j, a));
				}
				
				if (j != a) {
					power[idx][a][j] = min(power[idx][a][j], power[idx-1][i][j] + dist(i, a));
				}
				
			}
		}
		
		//printpower(idx);
		idx++;

	}
	if (idx == 0) {
		printf("0");
		return 0;
	}
	int min = 1e9;
	for(int i=0; i<5; i++) {
		for(int j=0; j<5; j++) {
			
			if (min > power[idx-1][i][j] && power[idx-1][i][j]) {
				min = power[idx-1][i][j];
			}
		}
	}
	
	printf("%d", min);
}
