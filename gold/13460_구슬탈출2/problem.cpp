#include <stdio.h> 
#include <vector>
#include <utility>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
char map[11][11];

int bx, by, rx, ry;
int obx, oby, orx, ory;


void printmap() {
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}

void resetMap() {
	bx = obx;
	by = oby;
	rx = orx;
	ry = ory;
}



int movemap(int dir) {
	
	bool blue = true;
	bool red = true;
	bool isbluefirst = false;
	
	int i = 0, j = 0;
	
	switch(dir) {
		case 0: // 왼쪽
			if (by < ry) {
				isbluefirst = true;
				
			}
			j = -1;
			break;
		case 1: // 오른쪽 
			if (by > ry) {
				isbluefirst = true;
				
			}
			j = 1;
			break;
		case 2: // 위
			if (bx < rx) {
				isbluefirst = true;
			
			}  
			i = -1;
			break;
		case 3: // 아래
			if (bx > rx) {
				isbluefirst = true;
				i = 1;
			}   
			i = 1;
			break;
		
	} 
	
	//printf("%d : %d %d %d %d || %d : %d %d \n", dir, bx, by, rx, ry, isbluefirst, i, j);
	
	if (isbluefirst) {
		while(blue || red) {
			if (map[bx + i][by + j] == '#') {
				blue = false;
			}
			
			if (blue) {
				bx += i;
				by += j;
			}
			
			if (map[bx][by] == 'O') {
				return -1;
			}
			
			
			if (map[rx + i][ry + j] == '#') {
				red = false;
			}
			if ((rx + i == bx) && (ry + j == by)) {
				red = false;
			}
			
			
			if (red) {
				rx += i;
				ry += j;	
			}
			if (map[rx][ry] == 'O') {
				return 1;
			}
			
		}
	} 
	else {
		while(blue || red) {
			
			if (map[rx + i][ry + j] == '#') {
				red = false;
			}
			
			
			if (red) {
				rx += i;
				ry += j;	
			}
			
			if (map[rx][ry] == 'O') {
				red = false;
			}
			
			
			
			if (map[bx + i][by + j] == '#') {
				blue = false;
			}
			if ((bx + i == rx) && (by + j == ry)) {
				if (map[rx][ry] == 'O') {
					return -1;
				}
				blue = false;
			}
			
			if (blue) {
				bx += i;
				by += j;
			}
			
			if (map[bx][by] == 'O') {
				return -1;
			}
			
		}
		
		if (map[rx][ry] == 'O') {
			return 1;
		}
		
	} 
	
	
	
	return 0;
	
}

int getResult(int dirbit, int max) {
	
	resetMap();
	
	for(int i = 0; i < (max == -1 ? 10 : max); i++) {
		int temp = dirbit%4;
		dirbit = dirbit >> 2;
		int success = movemap(temp);
		
		if (success == 1) {
			return i+1;
		}
		
		if (success == -1) {
			return -1;
		}
	}

	
	
	
	return -1;
}


int main() {
	scanf("%d %d", &N, &M);
	
	
	for(int i=0; i<N; i++) {
		scanf("%s", map[i]);
	}
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			if(map[i][j] == 'B') {
				obx = i;
				oby = j;
			}
		
			if (map[i][j] == 'R') {
				orx = i;
				ory = j;
			}
			
		}
	}
	
	int max = -1;
	
	for(int i=0; i< (1<<20); i++) {
		int temp = getResult(i, max);
		if (max < temp) {
			max = temp;
		}
		
	}
	
	
	printf("%d", max);
	
}
