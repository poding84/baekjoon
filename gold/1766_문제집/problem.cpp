#include <stdio.h> 
#include <vector>
#include <utility>
#include <queue>
#include <string.h>
#include <map>
#include <math.h>

using namespace std;

int degree[32023];

vector<int> graph[32023];
priority_queue<int> q;

int main() {
	
	int N, M;
	
	scanf("%d %d", &N, &M);
	
	for(int i=0; i<M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);	
		graph[a].push_back(b);
		degree[b] += 1;
	}
	
	for(int i=1; i<=N; i++) {
		if (degree[i] == 0) {
			q.push(-i);
		}
	}
	
	while(!q.empty()) {
		int node = -q.top();
		q.pop();
		printf("%d ",node);
		for(int i=0; i<graph[node].size(); i++) {
			degree[graph[node][i]] -= 1;
			if (degree[graph[node][i]] == 0) {
				q.push(-graph[node][i]);
			}
		}
	}
	
	
	
	
	
}
