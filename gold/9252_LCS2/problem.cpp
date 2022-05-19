#include <bits/stdc++.h>

using namespace std;

char a[1010];
char b[1010];

int dp[1010][1010];
pair<int, int> nextchar[1010][1010];
int len_a, len_b;

int sum;

int getLCS(int ea, int eb) {
	//printf("%d %d\n", ea, eb);
	//sum += 1;
	if (ea >= len_a) {
		return 0;
	}
	if (eb >= len_b) {
		return 0;
	}
	
	
	
	
	int x, y;
	
	if (dp[ea][eb] != -1 ) {
		return dp[ea][eb];
	}
	
	if (a[ea] == b[eb])  {
		dp[ea][eb] = getLCS(ea+1, eb+1) + 1;
		nextchar[ea][eb] = {ea+1, eb+1};
		return dp[ea][eb];
	}
	else {
		x = getLCS(ea+1, eb);	
		y = getLCS(ea, eb+1);
	}
	
	
	
	
	
	
	if (x>y) {
		dp[ea][eb] = x;
		nextchar[ea][eb] = {ea+1, eb};
	}
	else {
		dp[ea][eb] = y;
		nextchar[ea][eb] = {ea, eb+1};
	}
	
	return dp[ea][eb];
	
	
}


int main() {
	
	scanf("%s", a);
	scanf("%s", b);
	
	len_a = strlen(a);
	len_b = strlen(b);	
	
	for(int i=0; i<=1005; i++) {
		for(int j=0; j<=1005; j++) {
			dp[i][j] = -1;
		}
	}
	
	
	int p = getLCS(0, 0);
	printf("%d", p);
	
	if (p>0) {
		printf("\n");
		if (a[0] == b[0]) {
			printf("%c", a[0]);
		}
		int i = nextchar[0][0].first;
		int j = nextchar[0][0].second;
		while(true) {
			if (i == 0 && j == 0) {
				break;
			}
			
			if (a[i] == b[j]) {
				printf("%c", a[i]);
			}
			
			pair<int, int> temp = nextchar[i][j];
			
			i = temp.first;
			j = temp.second;
		}
	}
	
	
	
	
//	printf("\n%d", sum);
	
}
