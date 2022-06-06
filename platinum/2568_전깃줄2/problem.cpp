#include <stdio.h> 
#include <vector>
#include <utility>
#include <queue>
#include <string.h>
#include <map>
#include <math.h>

using namespace std;
int n;

void printlis(vector<int> lis) {
	printf("\n--------------\n");
	for(int i=0; i<lis.size(); i++) {
		printf("%d ", lis[i]);
	}
	
}

void printarr(int* lis) {
	printf("\n-----arr------\n");
	for(int i=0; i<n; i++) {
		printf("%d ", lis[i]);
	}
	
}


int main() {
	
	
	
	scanf("%d", &n);
	
	priority_queue<pair<int, int> > pq;
	
	for(int i=0; i<n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		
		pq.push({-a, b});
		
		
	}
	
	vector<int> lis;
	vector<int> origin;
	int index[100010];
	int idx = 0;
	
	
	while(!pq.empty()) {
		int a = -pq.top().first;
		int b = pq.top().second;
		int last = lis.size()-1;
		pq.pop();
		origin.push_back(a);
		
		if (lis.size() == 0) {
			lis.push_back(b);
			index[idx] = 0;
		}
		
		else if (lis[last] < b) {
			lis.push_back(b);
			index[idx] = lis.size()-1;
		}
		else {
			int id = lower_bound(lis.begin(), lis.end(), b) - lis.begin();		
			lis[id] = b;
			
			index[idx] = id;
		}
		
		idx++;
		
	}
	int ans = lis.size();
	printf("%d\n", n-ans);
	ans--;
	
	int anslist[100010];
	anslist[ans + 1]  = -1;
	for(int i=n-1; i>=0; i--) {
		if (ans == -1) {
			break;
		}
		if (index[i] == ans) {
			anslist[ans] = i;
			ans--;
		}
	}
	int notprintidx = 0;
	for(int i=0; i<n; i++) {
		if (anslist[notprintidx] == i) {
			notprintidx++;
			continue;
		}
		printf("%d\n", origin[i]);
	}
 	
	
}
