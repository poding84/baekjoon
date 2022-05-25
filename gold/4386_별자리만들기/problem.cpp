#include <stdio.h> 
#include <vector>
#include <utility>
#include <queue>
#include <string.h>
#include <map>
#include <math.h>

using namespace std;

int parent[110];

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
	int n;
	
	scanf("%d", &n);
	
	priority_queue<pair<float, pair<float, float> > > pq;
	
	vector<pair<float, float> > v;
	
	
	for(int i=0; i<n; i++) {
		float a, b;
		scanf("%f %f", &a, &b);
		v.push_back({a, b});
		for(int j=0; j<i; j++) {
			float x, y;
			x = a-v[j].first;
			y = b-v[j].second;
			pq.push({-x*x-y*y, {j, i}});
		}
	}
	
	
	
	int cnt = 0;
	float tot = 0;
	
	while(!pq.empty()) {
		if (cnt == n-1) {
			break;
		}
		
		
		float dist = -pq.top().first;
		int node1 = pq.top().second.first;
		int node2 = pq.top().second.second;
		pq.pop();
		
		int par1 = getParent(node1);
		int par2 = getParent(node2);
		
		if(par1 == par2) {
			continue;
		}
		
		parent[par1] = par2;
		
		tot += sqrt(dist);
		cnt++;
	}
	
	printf("%f", tot);
	
	
}
