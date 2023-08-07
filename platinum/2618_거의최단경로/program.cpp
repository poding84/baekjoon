#include <stdio.h> 
#include <vector>
#include <utility>
#include <queue>

using namespace std;

void removeLine(vector<pair<int, int> >* graph, int node1, int node2) {
	for(int i=0; i<graph[node1].size(); i++) {
		if (graph[node1][i].second == node2) {
			graph[node1].erase(graph[node1].begin() + i);
			break;
		}
	}

	return;
}

int solve_case(int N, int M, int start, int end, vector<pair<int, int> >* graph, bool isAlmostMin) {
	int distArr[510];
	for(int i=0; i<N; i++) {
		distArr[i] = 2e9;
	}
	
	
	
	priority_queue<pair<int, int> > pq; // (distance, currnode)
	pq.push(make_pair(0, start));
	distArr[start] = 0;
	
	
	vector<int> lastvisitedNodes[510];
	
	while(!pq.empty()) {
		int currNode = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();
		if (distance > distArr[currNode]) continue;
		
		for(int i=0; i<graph[currNode].size(); i++) {
			int nextNode = graph[currNode][i].second;
			int nextDist = graph[currNode][i].first + distance;
			
			if (nextDist < distArr[nextNode]) {
				lastvisitedNodes[nextNode].clear();
				lastvisitedNodes[nextNode].push_back(currNode);
				distArr[nextNode] = nextDist;
				pq.push(make_pair(-nextDist, nextNode));
			}
			else if(nextDist == distArr[nextNode]) {
				lastvisitedNodes[nextNode].push_back(currNode);
			}
		}
		
	}
	if (distArr[end] >= 2e9) {
		return -1;
	}
	
	if (!isAlmostMin) {		
		return distArr[end];
	}
	
	queue<int> q;
	bool visited[510];
	for (int i=0; i<N; i++) {
		visited[i] = false;
	}
	
	q.push(end);

	while(!q.empty()) {
		int currNode = q.front();
		q.pop();
		if (currNode == start) {
			continue;
		}
		if (visited[currNode]) {
			continue;
		}
		visited[currNode] = true;
	
		for(int i=0; i<lastvisitedNodes[currNode].size(); i++) {
			q.push(lastvisitedNodes[currNode][i]);
			removeLine(graph, lastvisitedNodes[currNode][i], currNode);
		}	

		
	}

	
	return solve_case(N, M, start, end, graph, false);
}



int main() {
//	while (true){
//		int N, M;
//		scanf("%d %d", &N, &M);
//		if (N == 0 && M == 0) {
//			break;
//		}
//		printf("%d\n", solve_case(N, M));
//	}	
	vector<int> ans;
	
	while (true) {
		int N, M;
		scanf("%d %d", &N, &M);
		if (N == 0 && M == 0) {
			break;
		}
		
		
		int start, end;
		scanf("%d %d", &start, &end);
		
		vector<pair<int, int> > graph[510]; // (distance, nextNode)
		for(int i=0; i<M; i++) {
			int a, b, d;
			scanf("%d %d %d", &a, &b, &d);
			graph[a].push_back(make_pair(d, b));
		}
		ans.push_back(solve_case(N, M, start, end, graph, true));
	}
	
	for(int i=0; i<ans.size(); i++) {
		printf("%d\n", ans[i]);
	}
	
	
	return 0;
}

