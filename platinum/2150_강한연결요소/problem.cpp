#include <stdio.h> 
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;



vector<int> graph[10010];
vector<int> reversed[10010];
vector<int> vec[10010];


stack<int> scc;


bool visited[10010];
bool rvisited[10010];

int cnt = 0;

void dfs(int node) {
	if (visited[node]) {
		return;
	}
	
	visited[node] = true;
	for(int i=0; i<graph[node].size(); i++) {
		dfs(graph[node][i]);
	}
	
	scc.push(node);
	
	
	return;
}

void rdfs(int node) {
	if (rvisited[node]) {
		return;
	}
	
	rvisited[node] = true;
	for(int i=0; i<reversed[node].size(); i++) {
		rdfs(reversed[node][i]);
	}
	
	vec[cnt].push_back(node);
	
	
	return;
}



int main() {
	
	int v, e;
	scanf("%d %d", &v, &e);
	
	for(int i=0; i<e; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		
		graph[a].push_back(b);
		reversed[b].push_back(a);
		
	}
	
	for(int i=1; i<=v; i++) {
		dfs(i);
	}
	
	
	
	
	
	while(!scc.empty()) {
		int node = scc.top();
		scc.pop();
		if (rvisited[node]) {
			continue;
		}
		rdfs(node);
		cnt++;
	}
	
	priority_queue<pair<int, vector<int> > > pq;
	
	
	for(int i=0; i<cnt; i++) {
		sort(vec[i].begin(), vec[i].end());
		pq.push({-vec[i][0], vec[i]});
		
	}
	printf("%d\n", cnt);
	while(!pq.empty()) {
		vector<int> vv = pq.top().second;
		pq.pop();
	
		for(int i=0; i<vv.size(); i++) {
			printf("%d ", vv[i]);
		}
		printf("-1\n");
	}
	
	
	
}
