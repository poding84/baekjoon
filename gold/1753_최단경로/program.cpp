#include <stdio.h>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

int V, E;
int start;

vector<pair<int, int> > dist[20010];

int minDist[20010];



int main() {
	scanf("%d %d", &V, &E);
	scanf("%d", &start);
	
	for(int i=0; i<E; i++) {
		int a, b, d;
		scanf("%d %d %d", &a, &b, &d);
		dist[a].push_back(make_pair(b,d));
	}
	
	for (int i=1; i<=V; i++) {
		minDist[i] = 2e9;
	}
	
	minDist[start] = 0;
	
	priority_queue<pair<int, int> > pq;
	
	pq.push(make_pair(0, start));
	
	
	while(!pq.empty()) {
		int currNode = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();
		
		if (minDist[currNode] < distance) continue;
		
		for(int i=0; i<dist[currNode].size(); i++) {
			int nextNode = dist[currNode][i].first;
			int nextDist = dist[currNode][i].second + distance;
			
			if (nextDist < minDist[nextNode]) {
				minDist[nextNode] = nextDist;
				pq.push(make_pair(-nextDist, nextNode));
			}
			
			
		}
		
		
	}
	
	for(int i=1; i<=V; i++) {
		if(minDist[i] == 2e9) {
			printf("INF\n");
		}
		else {
			printf("%d\n", minDist[i] );
		}
	}
	
	
	return 0;
}