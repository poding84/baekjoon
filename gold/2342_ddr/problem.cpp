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

int main() {
	int idx = 0;
	int before;
	while(true) {
		int a;
		scanf("%d", &a);
		if (idx == 0) {
			power[0][0][a] = dist(0, a);
			power[0][a][0] = dist(a, 0);
			idx++;
			continue;
		}
		
		for(int i=0; i<5; i++) {
			power[idx]
		}
		
		for(int i=0; i<5; i++) {
			
		}
		
		
		
		idx++;

	}
	
	
}
