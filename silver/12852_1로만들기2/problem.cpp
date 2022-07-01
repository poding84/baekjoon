#include <stdio.h> 
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int prevv[1000010];


int main() {
	
	int x;
	
	scanf("%d", &x);
	
	queue<int> q;
	
	
	q.push(x);
	
	while(!q.empty()) {
		int curr = q.front();
		
		if (curr == 1) {
			break;
		}
		
		
		q.pop();
		
		if ( 1== 1 ){
			int a = curr - 1;
			if (prevv[a] == 0) {
				prevv[a] = curr;
				q.push(a);
			}
		}

		if (curr%2 == 0) {
			int a = curr/2;
			if (prevv[a] == 0) {
				prevv[a] = curr;
				q.push(a);
			}
		}
		
		if (curr%3 == 0) {
			int a = curr/3;
			if (prevv[a] == 0) {
				prevv[a] = curr;
				q.push(a);
			}
		}
		
	}
	vector<int> ans;
	int curr=1;
	ans.push_back(curr);
	while(!(curr == x)) {
		ans.push_back(prevv[curr]);
		curr = prevv[curr];
	}
	
	printf("%d\n", ans.size()-1);
	
	for(int i=ans.size() - 1; i>=0; i--) {
		printf("%d ", ans[i]);
	}
	
}
