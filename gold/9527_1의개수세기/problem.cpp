#include <stdio.h> 
#include <vector>
#include <utility>
#include <queue>
#include <string.h>
#include <map>
#include <math.h>

using namespace std;

long long dp[110];


long long getonenum(long long a) {
	if (a == 0) {
		return 0;
	}
	int x;
	long long b = a;
	long long cnt = -1;
	while(b > 0) {
		b = b/2;
		cnt++;
	}
	long long one = 1;
	long long head = (one<<cnt);
	long long r = a - head;

	if (r == 0) {
		return dp[cnt-1] + 1;
	}
	else {
		return dp[cnt-1] + getonenum(r)+(r+1);
	}

}



int main() {
	long long a, b;
	scanf("%lld %lld", &a, &b);
	
	long long temp = b;
	long long cnt = 0;
	while(temp > 0) {
		temp = temp/2;
		cnt++;
	}
	dp[0]=1;
	
	for(int i=1; i<=cnt; i++) {
		long long one = 1;
		dp[i]= 2*dp[i-1] + (one<<i);
	}

	
	printf("%lld", getonenum(b) - getonenum(a-1));
	
	
}
