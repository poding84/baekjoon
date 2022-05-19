#include <stdio.h> 
#include <vector>
#include <utility>
#include <queue>

using namespace std;


int N;
int a[1000010];

vector<int> lis;

vector<int> indexlis;
vector<int> captureindex;


int getIndex(int num) {
	int idx = lower_bound(lis.begin(), lis.end(), num) - lis.begin();
	
	return idx;
	
	
}

void capture() {
	for(int i=lis.size() - 1; i>=0; i--) {
		capturelis[i] = lis[i];
		if (i == 0) {
			break;
		}
		
		if (capturelis[i-1] < capturelis[i]) {
			break;
		}
	}
}

int main() {
	scanf("%d", &N);
	
	for(int i=0; i<N; i++ ) {
		scanf("%d", a+i);
	}
	
	lis.push_back(a[0]);
	capturelis.push_back(a[0]);
	int ans = 1;
	for(int i=1; i<N; i++ ) {
		if (lis[ans-1] < a[i]) {
			lis.push_back(a[i]);
			indexlis.push_back(i);
			ans++;
		}
		else {
			int index = getIndex(a[i]);
			lis[index] = a[i];
			if (index == ans - 1) {
				capture();
			}
			
		}
		
		printf("\n------%d------\n", a[i]);
		for(int i=0; i<ans; i++) {
			printf("%d ", capturelis[i]);
		}
		
		printf("\n");
		for(int i=0; i<ans; i++) {
			printf("%d ", lis[i]);
		}
		
		
	}
	
	printf("%d", ans);
	

	printf("\n");
	for(int i=0; i<ans; i++) {
		printf("%d ", capturelis[i]);
	}
	
	
}
