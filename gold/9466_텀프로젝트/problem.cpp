#include <bits/stdc++.h>

using namespace std;


int solveProblem() {
	int n;
	int a[100010];
	int degree[100010];
	scanf("%d", &n);
	
	for(int i=1; i<=n; i++) {
		degree[i]=0;
	}
	
	for(int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
		degree[a[i]]++;
	}
	
	queue<int> q;
	
	for(int i=1; i<=n; i++) {
		if (degree[i] == 0) {
			q.push(i);
		}
	}
	int cnt=0;
	while(!q.empty()) {
		int currstud = q.front();
		q.pop();
		cnt++;
		degree[a[currstud]] -= 1;
		if (degree[a[currstud]] == 0) {
			q.push(a[currstud]);
		}
		
	}
	
	
	
	return cnt;
	
}



int main() {
	
	int x;
	scanf("%d", &x);
	
	for(int i=0; i<x; i++) {
		printf("%d\n", solveProblem());
	}
	
	
}
