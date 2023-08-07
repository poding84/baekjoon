#include <stdio.h> 
#include <vector>
#include <utility>
#include <queue>
#include <string.h>
#include <map>


using namespace std;

int arr[10][10];
vector<int> poss[10][10];
int curr[10][10];

pair<int, int> getNext(int i, int j) {
	j = j+1;
	if (j == 9) {
		return {i+1, 0};
	}
	else {
		return {i, j};
	}
}

pair<int, int> getPrev(int i, int j) {
	j--;
	if (j == -1) {
		i--;
		j = 8;
	}
	
	if (arr[i][j] == 0) {
		return {i, j};
	}
	else {
		return getPrev(i, j);
	}
	
}

bool issame(int num, int x, int y) {
	if (arr[x][y] == 0) {
		if (poss[x][y].size() == 0) {
			return false;
		}
		else {
			if (poss[x][y][curr[x][y]] == num) {
				return true;
			}
			else {
				return false;
			}
		}
	}
	else if(arr[x][y] == num) {
		return true;
	} 
	else {
		return false;
	}
	
	
}

bool check(int num, int x, int y) {
	for(int i=0; i<9; i++) {
		if (issame(num, x, i)) {
			return false;
		}
	}
	
	for(int i=0; i<9; i++) {
		if (issame(num, i, y)) {
			return false;
		}
	}
	
	
	int startx = x - x%3;
	int starty = y - y%3;
	
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			if (issame(num, startx + i, starty + j)) {
				return false;
			}
		}
	}
	
	return true;

}

vector<int> getPossList(int x, int y) {
	vector<int> v;
	for(int i=1; i<=9; i++) {
		if (check(i, x, y)) {
			v.push_back(i);
		}
	}
	
	
	
	return v;
}

void printarr(int arr[][10]) {
	
	for(int i=0; i<9; i++) {
		for(int j=0; j<9; j++) {
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}
}

void printcurr() {
	
	for(int i=0; i<9; i++) {
		for(int j=0; j<9; j++) {
			if (arr[i][j] == 0) {
				if (poss[i][j].size() == 0) {
					printf("%d",  arr[i][j]);
				}
				else {
					printf("%d",  poss[i][j][curr[i][j]]);
				}
			}
			else {
				printf("%d",  arr[i][j]);
			}
			
		}
		printf("\n");
	}
	
}

int main() {
	
	
	for(int i=0; i<9; i++) {
		for(int j=0; j<9; j++) {
			scanf("%1d", &arr[i][j]);
			curr[i][j] = -1;
		}
	}
	
	int i=0;
	int j =0;
	
	while (!(i == 9 && j == 0)) {
//		printf("%d %d\n", i, j);
//		printcurr();
		if (arr[i][j] != 0) {
			pair<int, int> p = getNext(i, j);
			i = p.first;
			j = p.second;
			continue;
		}
		
		if (poss[i][j].size() == 0) {
			poss[i][j] = getPossList(i, j);
			if (poss[i][j].size() == 0) {
				curr[i][j] = -1;
				pair<int, int> p = getPrev(i, j);
				i = p.first;
				j = p.second;
				continue;
			}
			else {
				curr[i][j] = 0;
				pair<int, int> p = getNext(i, j);
				i = p.first;
				j = p.second;
				continue;
			}
		}
		else if (poss[i][j].size() == curr[i][j] + 1) {
			poss[i][j].clear();
			curr[i][j] = -1;
			pair<int, int> p = getPrev(i, j);
			i = p.first;
			j = p.second;
			continue;
		}
		else {
			curr[i][j]++;
			pair<int, int> p = getNext(i, j);
			i = p.first;
			j = p.second;
			continue;
		}
		
		break;
		
		
	}
	
	printcurr();
	
	
	return 0;
}
