#include <stdio.h> 
#include <vector>
#include <utility>

using namespace std;

int N, W;

int mintable[1010][1010];
pair<int, int> dirtable[1010][1010];

vector<pair<int, int> > cases;

pair<int, int> pointA = make_pair(1, 1);
pair<int, int> pointB;


void printTable() {
	for(int i=0; i<=W; i++) {
		for(int j=0; j<=W; j++) {
			if (mintable[i][j] != 2e9) {
				printf("%4d ", mintable[i][j]);
			}
			else {
				printf("%4d ", -1);
			}
			
		}
		printf("\n");
	}
	printf("-----------\n");
}

void printDir() {
	for(int i=0; i<=W; i++) {
		for(int j=0; j<=W; j++) {
				printf("%4d %4d|", dirtable[i][j].first, dirtable[i][j].second);
		}
		printf("\n");
	}
	printf("-----------\n");
}

void setTable() {
	for(int i=0; i<=W; i++) {
		for(int j=0; j<=W; j++) {
			mintable[i][j] = 2e9;
		}
	}
}

int abs(int x) {
	return x>0 ? x : -x;
}

int dist(pair<int, int> point1, pair<int, int> point2) {
	return abs(point1.first - point2.first) + abs(point1.second - point2.second);
}

int dist(int a, int b) {
	if (a == 0) {
		return dist(pointA, cases[b-1]);
	}
	else if(b == 0) {
		return dist(pointB, cases[a-1]);
	}
	return dist(cases[a-1], cases[b-1]);
}




void goForward(int a, int b, int i) {
	int val = mintable[a][b];
	int valA = val + dist(a, i);
	if (valA < mintable[i][b]) {
		mintable[i][b] = valA;
		dirtable[i][b] = make_pair(a,b);
	}
	int valB = val + dist(i, b);
	if (valB < mintable[a][i]) {
		mintable[a][i] = valB;
		dirtable[a][i] = make_pair(a,b);
	}
}

int changeVal(pair<int, int> point1, pair<int, int>point2) {
	if (point1.first == point2.first) {
		return 2;
	}
	else {
		return 1;
	}
}

int main() {
	scanf("%d", &N);
	scanf("%d", &W);
	pointB = make_pair(N, N);
	
	for (int i=1; i<=W; i++) {
		int case_x, case_y;
		scanf("%d %d", &case_x, &case_y);
		cases.push_back(make_pair(case_x, case_y));
	}
	
	setTable();
	
	
	for(int i=1; i<=W; i++) {
		pair<int, int> point = cases[i-1];
		if (i == 1) {
			mintable[0][1] = dist(point, pointB);
			mintable[1][0] = dist(point, pointA);
			//printTable();
			continue;
		}
		
		
		for(int j=0; j<i-1; j++) {
			int a, b;
			a = i-1;
			b = j;
			goForward(a, b, i);
			goForward(b, a, i);
			
		}
		
	//	printTable();
	}
	
	//printDir();
	int answerArr[1010];
	int minval = 2e9;
	pair<int, int> minPoint;
	for(int i=0; i<W; i++) {
		if (minval > mintable[i][W]) {
			minval = mintable[i][W];
			minPoint = make_pair(i ,W);
		}
		
		if (minval > mintable[W][i]) {
			minval = mintable[W][i];
			minPoint = make_pair(W ,i);
		}
	}
	
	printf("%d\n",minval);
	for(int i=W-1; i>=0; i--) {
		answerArr[i] = changeVal(minPoint, dirtable[minPoint.first][minPoint.second]);
		minPoint = dirtable[minPoint.first][minPoint.second];
	}
	for(int i=0; i<W; i++) {
		printf("%d\n", answerArr[i]);
	}
}



