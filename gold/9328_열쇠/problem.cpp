#include <stdio.h> 
#include <vector>
#include <utility>
#include <queue>
#include <cstring>

using namespace std;



int h, w;
	
char map[110][110];
bool visited[110][110];
bool isOpened[100];

int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};


void printmap() {
	for(int i=0; i<h; i++) {
		for(int j=0; j<w; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}

int solve() {
	for (int i=0; i<=100; i++) {
		isOpened[i] = false;
	}
	
	for (int i=0; i<=100; i++) {
		for(int j=0; j<=100; j++) {
			visited[i][j] = false;
		}
	}
	
	int ans = 0;
	
	scanf("%d %d", &h, &w);
	
	for(int i=0; i<h; i++) {
		scanf("%s", map[i]);
	}
	char key[100];
	
	scanf("%s", key);
	
	for(int i=0; i<strlen(key); i++) {
		isOpened[key[i] - 32] = true;
	}

	queue<pair<int, int> > q;
	queue<pair<int, int> > locked;
	

	
		for(int i=0; i<h; i++) {
		if (map[i][0] != '*') {
			q.push({i, 0});
		}
		if (map[i][w-1] != '*') {
			q.push({i, w-1});
		}
	}
	
	for(int i=1; i<w-1; i++) {
		if (map[0][i] != '*') {
			q.push({0, i});
		}
		if (map[h-1][i] != '*') {
			q.push({h-1, i});
		}
	}
	
	while(!q.empty() || !locked.empty()) { // q에는 별도 아니고, 맵 밖의 점도 아닌 점들이 들어있음. 
		if (q.empty()) {
			bool temp = true;
			while (!locked.empty()) {
				int currx, curry;
				currx = locked.front().first;
				curry = locked.front().second;
				char c = map[currx][curry];
				
				locked.pop();
				
				if (isOpened[c]) {
					temp = false;
				}
				q.push({currx, curry});
			}
			if (temp) {
				break;
			}
		}
		int currx, curry;
		currx = q.front().first;
		curry = q.front().second;
		q.pop();
		
		if (visited[currx][curry]) {
			continue;
		}
		
		char c = map[currx][curry];
		
		
	//	printf("%d %d : %c\n", currx, curry, c);
		switch(c) {
			case '.' :
				break;
			case '$' : 
				ans += 1;
				break;
			default :
				if (c > 'Z') { //소문자라면 
					isOpened[c - 32] = true; 
				} else {
					if (!isOpened[c]) {
						locked.push({currx, curry});
						continue;
					}
				}
				break;
		}
		
		visited[currx][curry] = true;
		
		for(int i=0; i<4; i++) {
			int nextx = currx + dir[i][0];
			int nexty = curry + dir[i][1];
			
			if (!(0 <= nextx && nextx <h)) {
				continue;
			}
			
			if (!(0 <= nexty && nexty <w)) {
				continue;
			}
			
			if (map[nextx][nexty] == '*') {
				continue;
			}
			
			if (visited[nextx][nexty]) {
				continue;
			}
			
			q.push({nextx, nexty});
			
		}
		
		
		
		
	}
	
	
	
	return ans;
}




int main () {
	
	int x;
	
	scanf("%d", &x);
	
	for(int i=0; i<x; i++) {
		printf("%d\n", solve());
	}
	
	
	return 0;
}
