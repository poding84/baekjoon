#include <stdio.h> 
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;

char palin[2525];
int n;
int sep[5050];

int dp[2525];


int getsep(int s, int e) {
	int start, end, cnt;
	int mid = (s+e)/2;
	if ((s+e)%2 == 0) {
		if (s == e) {
			return 1;
		}
		else {
			start = mid-1;
			end = mid+1;
			cnt = 1;
		}
	}
	else {
		start = mid;
		end = mid+1;
		cnt = 0;
	}
	
	
	while (end <= e) {
		if (palin[start] == palin[end]) {
			cnt++;
			start -= 1;
			end += 1;
		}
		else {
			break;
		}
	}
	
	return cnt;
}



void fillsep() {
	for(int i=0; i<n; i++) {
		sep[i] = getsep(0, i);
	}
	
	for(int i=1; i<n; i++) {
		sep[i + n - 1] = getsep(i, n-1);
	}
}

bool ispal(int s, int e) {
	if (s == e) {
		return true;
	}
	
	if (e - s == 1) {
		return palin[s] == palin[e];
	}
	
	int tot = s + e;
	
	if (tot%2 == 0) {
		
		int temp = e - tot/2;
		
		if (sep[tot] > temp) {
			return true;
		}
		else {
			return false;
		}
			
	}
	else {
		int temp = e - tot/2;
		
		if (sep[tot] >= temp) {
			return true;
		}
		else {
			return false;
		}
	}
	
	
	
	
	
}

int min(int a, int b) {
	return a>b ? b : a;
}


int main() {
	
	scanf("%s", palin);
	n = strlen(palin);
	
	fillsep();
	
	
	dp[0] = 0;
	dp[1] = 1;
	
	
	for(int i=2; i<=n; i++) {
		dp[i] = dp[i-1] + 1;
		for(int j=0; j<i; j++) {
			if (ispal(j, i-1)) {
				dp[i] = min(dp[j] + 1, dp[i]);
			}

		}
	}
	
//	for(int i=0; i<=n; i++) {
//		printf("%d ", dp[i]);
//	}
	
	printf("%d", dp[n]);
}
