#include <stdio.h>
#include <utility>
#include <vector>
#include <queue>



using namespace std;

vector<pair<int, int> > lineDist[4010]; //(next node, dist)



priority_queue<pair<int, int> > pq;



int foxDist[4010];
int wolfDist[4010][3]; //(node, isBeforeRun)
bool foxVisit[4010];
bool wolfVisit[4010][3];
int node, line;



int main() {
	
	scanf("%d %d", &node, &line);
	
	for (int i=0; i<line; i++)  {
		int a, b, d;
		
		scanf("%d %d %d", &a, &b, &d);
		
		lineDist[a].push_back(make_pair(b, d*2));
		lineDist[b].push_back(make_pair(a, d*2));
		
	}
	
	for (int i=1; i<=node; i++) {
		foxDist[i] = 2e9;
		foxVisit[i] = false;
		wolfDist[i][0] = 2e9;
		wolfDist[i][1] = 2e9;
		wolfVisit[i][0] = false;
		wolfVisit[i][1] = false;
	}
	foxDist[1] = 0;
	wolfDist[1][0] = 0;
	wolfDist[1][1] = 1e9;
	
	priority_queue<pair<int, int> > pq;
	
	pq.push(make_pair(0, 1));
	
	while(!pq.empty()) {
		int currNode = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();
		
		if (foxDist[currNode] < distance) continue;
		
		for (int i=0; i<lineDist[currNode].size(); i++) {
			int nextNode = lineDist[currNode][i].first;
			int nextDist = distance + lineDist[currNode][i].second;
			
			if (nextDist < foxDist[nextNode]) {
				foxDist[nextNode] = nextDist;
				pq.push(make_pair(-nextDist, nextNode));
			}
		}
		//printf("%d %d\n", currNode, distance);
	}
	
	priority_queue<pair<int, pair<int, int> > > pq_wolf; //(dist, (node, isRunBefore?))
	pq_wolf.push(make_pair(0, make_pair(1, 0)));
	
	while(!pq_wolf.empty()) {
		int currNode = pq_wolf.top().second.first;
		int isRunBefore = pq_wolf.top().second.second;
		int distance = -pq_wolf.top().first;
		pq_wolf.pop();
		
		if ( wolfDist[currNode][isRunBefore] < distance) continue;
		
		for (int i=0; i<lineDist[currNode].size(); i++) {
			
			int nextNode = lineDist[currNode][i].first;
			int nextDist;
			int nextRunWillBe;
			if (isRunBefore == 1) {
				nextDist = distance + (lineDist[currNode][i].second * 2);
				nextRunWillBe = 0;
			}
			else {
				nextDist = distance + (lineDist[currNode][i].second / 2);
				nextRunWillBe = 1;
			}
			
			
			if (nextDist < wolfDist[nextNode][nextRunWillBe]) {
				wolfDist[nextNode][nextRunWillBe] = nextDist;
				pq_wolf.push(make_pair(-nextDist, make_pair(nextNode, nextRunWillBe)));
			}
		}
		//printf("%d %d\n", currNode, distance);
	}
	
	
	
	int count = 0;
	
	for (int i=1; i<=node; i++) {
		int foxMin = foxDist[i];
		int wolfMin = min(wolfDist[i][0], wolfDist[i][1]);
		if ((foxMin-wolfMin) < 0) {
			count++;
		}
	}
	
	printf("%d", count);
	
	return 0;
}