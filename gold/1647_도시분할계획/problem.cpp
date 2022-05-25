#include <stdio.h> 
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

priority_queue<pair<int, pair<int, int> > > pq;

int parent[100010];

int getParent(int node) {
	if (parent[node] == 0) {
		return node;
	}
	else {
		int par = getParent(parent[node]);
		parent[node] = par;
		return par;
	}
}

int main() {
	
	int n, m;
	
	scanf("%d %d", &n, &m);
	
	for(int i=0; i<m; i++) {
		
		int a, b, c;
		
		scanf("%d %d %d", &a, &b, &c);
		
		pq.push({-c, {a, b}});
		
		
	}
	
	int totcost = 0;
	int cnt = 0;
	while(!pq.empty()) {
		if (cnt == n-2) {
			break;
		}
		int cost, node1, node2;
		cost = -pq.top().first;
		node1 = pq.top().second.first;
		node2 = pq.top().second.second;
		pq.pop();
		
		//printf("%d : %d %d\n", cost, node1, node2);
		
		int par1 = getParent(node1);
		int par2 = getParent(node2);
		
		if (par1 == par2) {
			continue;
		}
		
		parent[par1] = par2;

		totcost += cost;
		cnt++;
		
		
	}
	
	printf("%d", totcost);
	
	
	
	
}
