#include <stdio.h> 
#include <vector>
#include <utility>
#include <queue>
#include <string.h>
#include <map>
#include <math.h>

using namespace std;

int cost[1010][3];

int dp[3][1010][3];


int min(int x, int y) {
	if (x == 0) {
		return y;
	}
	
	if (y == 0) {
		return x;
	}
	
	return x>y ? y : x;
}

int main() {
	int n;
	
	scanf("%d", &n);
	
	for(int i=1; i<=n; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		cost[i][0] = a;
		cost[i][1] = b;
		cost[i][2] = c;
		
		if (i == 1) {
			dp[0][1][0] = a;
			dp[1][1][1] = b;
			dp[2][1][2] = c;
			
			continue;
		}
		
		for(int j=0; j<3; j++) {
			dp[j][i][0] = min(dp[j][i-1][1], dp[j][i-1][2]);
			dp[j][i][1] = min(dp[j][i-1][0], dp[j][i-1][2]);
			dp[j][i][2] = min(dp[j][i-1][0], dp[j][i-1][1]);
			
			if (dp[j][i][0]) dp[j][i][0] += a;
			if (dp[j][i][1]) dp[j][i][1] += b;
			if (dp[j][i][2]) dp[j][i][2] += c;
		}
		
	}
	
//	for(int i=1; i<=n; i++) {
//		for(int j=0; j<3; j++) {
//			printf("%d %d %d|", dp[j][i][0], dp[j][i][1], dp[j][i][2]);
//		}
//		printf("\n");
//	}
//	
	int x, y, z;
	x = min(dp[0][n][1], dp[0][n][2]);
	y = min(dp[1][n][0], dp[1][n][2]);
	z = min(dp[2][n][0], dp[2][n][1]);
	int ans = 1e9;
	ans = min(ans, x);
	ans = min(ans, y);
	ans = min(ans, z);
	
	printf("%d", ans);
	
}

