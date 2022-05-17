#include <stdio.h> 
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int N, M;
int arr[2010];

int dp[4010];

int getDpValue(int a, int b) {
	int x = a+b;
	int s, e;
	if (x%2 == 0) {
		s = x/2-1;
		e = x/2+1;
	}
	else {
		s = x/2;
		e = x/2+1;
	}
	int idx = 0;
	
	while(s>=0) {
		if (arr[s] == arr[e]) {
			s--;
			e++;
			idx++;
			continue;
		}
		else {
			break;
		}
	}
	
	return idx;
}


int getAnswer(int s, int e) {
	if (s == e) {
		return 1;
	}
	
	int x = s+e;
	if (x%2 == 0) {
		int true_s = x/2 - dp[x];

		if (true_s <= s) {
			return 1;
		}
		else {
			return 0;
		}
		
	}
	else {
		int true_s = x/2 - dp[x];
		
		if (true_s < s) {
			return 1;
		}
		else {
			return 0;
		}

	}
	
	
}

int main() {
	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		scanf("%d", &arr[i]);
	}
	
	for(int i=0; i<N; i++) {
		//0 ~ i
		int a = 0;
		int b = i;
		
		dp[a+b] = getDpValue(a, b);
		
		a= N-i-1;
		b= N-1;
		
		if(a != 0) {
			dp[a+b] = getDpValue(a, b);
		}
		
		//N-i-1 ~ N-1
	}

	
	
	scanf("%d", &M); 
	
	for(int i=0; i<M; i++) {
		int s, e;
		scanf("%d %d", &s, &e);
		printf("%d\n", getAnswer(s-1, e-1));
	} 
	
}