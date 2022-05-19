#include <stdio.h> 
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int N;
int mat[510];

int minmat[510][510];

int getMin(int s, int e) {
	if (minmat[s][e] != 0) {
		return minmat[s][e];
	}
	
	if (e - s == 1) {
		return 0;
	}
	
	if (e - s == 2) {
		return mat[s] * mat[s+1] * mat[s+2];
	}
	int min = -1;
	
	for(int i=s+1; i<e; i++) {
		int temp = getMin(s, i) + getMin(i, e) + mat[s] * mat[i] * mat[e];
		
		if (min == -1) {
			min = temp;
		}
		else {
			if (min > temp) {
				min = temp;
			}
		}
	}
	
	minmat[s][e] = min;
	return min;
}

int main() {
	
	scanf("%d", &N);
	int a, b;
	
	for(int i=0; i<N; i++) {
		scanf("%d %d", &a, &b);
		mat[i] = a;
	}
	mat[N] = b;
	
	
	printf("%d", getMin(0, N));
	
	
//	printf("\n");
//	for(int i=0; i<=N; i++) {
//		for(int j=0; j<= N; j++) {
//			printf("%d ", minmat[i][j]);
//		}
//		printf("\n");
//	}
//	
}
