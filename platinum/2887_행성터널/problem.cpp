#include <stdio.h> 
#include <vector>
#include <utility>
#include <queue>
#include <string.h>
#include <map>
#include <math.h>

using namespace std;

int N;

int abs(int x) {
	return x>0?x:-x;
}


priority_queue<pair<int, int> > pqx;
priority_queue<pair<int, int> > pqy;
priority_queue<pair<int, int> > pqz;
priority_queue<pair<int, pair<int, int> > > line;

int parent[100010];
void printparent() {
	for(int i=1; i<=N; i++) {
		printf("%d ", parent[i]);
	}
	printf("\n");
}
int getparent(int x) {
	if (parent[x] == 0) {
		return x;
	}
	else {
		int temp = getparent(parent[x]);
		parent[x] = temp;
		return temp;
	}
}


int main() {
	scanf("%d", &N);
	
	
	for(int i=1; i<=N; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		pqx.push({a, i});
		pqy.push({b, i});
		pqz.push({c, i});
	}
	
	for(int i=0; i<3; i++) {
		priority_queue<pair<int, int> > pq;
		switch(i) {
			case 0:
				pq = pqx;
				break;
			case 1:
				pq = pqy;
				break;
			case 2:
				pq = pqz;
				break;
		}
		int prev = 2e9;
		int prevnode;
		while(!pq.empty()) {
			int curr = pq.top().first;
			int currnode = pq.top().second;
			pq.pop();
			if (prev == 2e9) {
				prev = curr;
				prevnode = currnode;
				continue;
			}
			else {
				line.push({-abs(prev-curr), {currnode, prevnode}});
				prev = curr;
				prevnode = currnode;
			}
		}
	}
	
	int ans = 0;
	int cnt = 0;
	while(!line.empty()) {
		
		int dist = -line.top().first;
		int node1 = line.top().second.first;
		int node2 = line.top().second.second;
		line.pop();
		
		int par1 = getparent(node1);
		int par2 = getparent(node2);
		//printf("%d | %d %d, %d %d\n", dist, node1, node2, par1,par2);
		if (par1 == par2) {
			
		}
		else {
			parent[par1] = par2;
			ans += dist;
			cnt++;
		}
		//printparent();
	}
	printf("%d", ans);
	
}
