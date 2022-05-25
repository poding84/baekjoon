#include <stdio.h> 
#include <vector>
#include <utility>
#include <queue>
#include <string.h>
#include <map>
#include <math.h>
#include <set>


using namespace std;

bool notprime[4000010];

vector<int> prime;

int main() {
	
	int n;
	
	scanf("%d", &n);
	if (n == 1) {
		printf("0");
		return 0;
	}
	for(int i=2; i<=n; i++) {
		if (notprime[i]) {
			continue;
		}
		prime.push_back(i);
		for(int j=2; j*i<=n; j++) {
			notprime[j*i] = true;
		}
	}
	
	int i = 0;
	int j = 1;
	int ans = 0;
	
	int sum = prime[0];
	
	while(j <= prime.size()) {
		//printf("%d %d %d\n", i, j, sum);
		if (i == j) {
			break;
		}
		if (sum < n) {
			if (j == prime.size()) {
				break;
			}
			sum += prime[j];
			j++;
		}
		else if (sum > n) {
			sum -= prime[i];
			i++;
		}
		else {
			ans++;
			sum -= prime[i];
			i++;
			
		}
	}
	
	printf("%d", ans);
	
	
	
	
}
