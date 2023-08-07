#include <stdio.h> 
#include <vector>
#include <utility>
#include <queue>

using namespace std;


int N;
int a[1000010];
int index[1000010];


vector<int> lis;



int getIndex(int num) {
	int idx = lower_bound(lis.begin(), lis.end(), num) - lis.begin();
	
	return idx;
	
	
}

void printlis(int ans) {
	printf("\n");
	for(int i=0; i<ans; i++) {
		printf("%d ", lis[i]);
	}
}

void printidx() {
	printf("\n");
	for(int i=0; i<N; i++) {
		printf("%d ", index[i]);
	}
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
			index[i] = ans;
			ans++;
		}
		else {
			int indexx = getIndex(a[i]);
			lis[indexx] = a[i];
			index[i] = indexx;
			
		}
//		printf("\n------%d------\n", a[i]);
//		
//		printlis(ans);
//		printidx();
	}
	
	
	printf("%d", ans);
	printf("\n");
	vector<int> printans;
	for(int i=N-1; i>=0; i--) {
		if (ans == 0) {
			break;
		}
		if (index[i] == ans-1) {
			printans.push_back(a[i]);
			ans--;
		}
	}
	
	for(int i=printans.size()-1; i>=0; i--) {
		printf("%d ", printans[i]);
	}
	
	
	
}
