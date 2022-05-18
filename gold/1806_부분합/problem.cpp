#include <stdio.h> 
#include <vector>
#include <utility>
#include <queue>
#include <string.h>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

int N, S;
int s[100010];

int main() {
	
	scanf("%d %d", &N, &S);
	for(int i=0; i<N; i++) {
		int a;
		scanf("%d", &a);
		
		if (i == 0) {
			s[i] = a;
		}
		else {
			s[i] = s[i-1] + a;
		}		
	}
	
	
	int start = 0;
	int width = 1;
	
	bool success = false;
	
	if (s[N-1] < S) {
		printf("0");
		return 0;
	}
	
	
	while (start < N) {
		int end = start - width;
		int sum;
		if (end < 0) {
			sum = s[start];
		}
		else {
			sum = s[start] - s[end];
		}
		
		if (sum >= S) {
			success = true;
		}
		
		//printf("%d %d %d\n", sum, end, start);
		
		if (!success) {
			start += 1;
			width += 1;
		}
		else {
			if (sum < S) {
				start++;
				continue;
			}
			while (sum >= S) {
				width--;
				end = start - width;
				sum = s[start] - s[end];
			}
			width++;
			start++;
		}
		
		
		
		
	}
	
	printf("%d", width);
	
	
	
}
