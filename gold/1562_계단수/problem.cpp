#include <stdio.h> 
#include <vector>
#include <utility>
#include <queue>
#include <math.h>


using namespace std;

long long dp[110][11][11];

long long ansfunc(int n) {
	long long ans = 0;
	for(int i=1; i<10; i++) {
		for(int j=0; j<10; j++) {
			ans += dp[n][i][j];
		}
	}
	return ans;
}


int main() {
	
	int N;
	
	scanf("%d", &N);
	
	
	dp[10][9][0] = 1;
	dp[10][0][9] = 1;
	for(int i=11; i<=N; i++) {
		
	}
	
	
	long long ans=0;
	
	for(int i=1; i<=40; i++) {
		ans += ansfunc(i);
	}
	
	
	printf("%lld", ans);
	
	
	
	
}
