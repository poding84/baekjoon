#include <stdio.h> 
#include <vector>
#include <utility>
#include <queue>
#include <math.h>


using namespace std;

int mod = 1000000000;

int dp[101][1030][10];

int sumprint(int x) {
	int sum = 0;
	for(int i=0; i<10; i++) {
		sum += dp[x][1023][i];
		sum %= 1000000000;
	}
	return sum;
}

int main() {
	
	int N;
	
	scanf("%d", &N);
	
	if (N<10) {
		printf("0");
		return 0;
	}
	

	
	for(int i=1; i<10; i++) {
		dp[1][1<<i][i] = 1;
	}
	
	for(int i=2; i<=N; i++) {
		for(int j=0; j<1024; j++) {
			dp[i][j|(1<<0)][0] = (dp[i][j|(1<<0)][0] + dp[i-1][j][1] ) % mod;
			for(int k=1; k<9; k++) {
				dp[i][j|(1<<k)][k] = (dp[i][j|(1<<k)][k] + dp[i-1][j][k-1] ) % mod;
				dp[i][j|(1<<k)][k] = (dp[i][j|(1<<k)][k] + dp[i-1][j][k+1] ) % mod;
			}
			dp[i][j|(1<<9)][9] = (dp[i][j|(1<<9)][9] + dp[i-1][j][8] ) % mod;
		}
	}
	
	printf("%d", sumprint(N));
	
	
}
