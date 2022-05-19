#include <stdio.h> 
#include <vector>
#include <utility>
#include <queue>

using namespace std;


int N;
int a[1000010];

vector<int> lis;


int getIndex(int num) {
	int idx = lower_bound(lis.begin(), lis.end(), num) - lis.begin();
	
	return idx;
	
	
}

int main() {
	scanf("%d", &N);
	
	for(int i=0; i<N; i++ ) {
		scanf("%d", a+i);
	}
	
	lis.push_back(a[0]);
	int ans = 1;
	for(int i=1; i<N; i++ ) {
		if (lis[ans-1] < a[i]) {
			lis.push_back(a[i]);
			ans++;
		}
		else {
			int index = getIndex(a[i]);
			lis[index] = a[i];
		}
	}
	
	printf("%d", ans);
	
//	
//	printf("\n");
//	for(int i=0; i<ans; i++) {
//		printf("%d ", lis[i]);
//	}
//	
	
	
	
}
