#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int N, M;


vector<int> graph[1010];
queue<int> q;



int startnode[1010];
bool visited[1010];

void printgraph() {
	for(int i=1; i<=N; i++) {
		printf("%d : ", i);
		for(int j=0; j<graph[i].size(); j++) {
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}
}

void printstartnode() {
	for(int i=1; i<=N; i++) {
		printf("%d ", startnode[i]);
	}
	printf("\n");
}

void printvisited() {
	for(int i=1; i<=N; i++) {
		printf("%d ", visited[i]);
	}
	printf("\n");
}


int main() {
	
	scanf("%d %d", &N, &M);
	
	for(int i=0; i<M; i++) {
		int a;
		scanf("%d", &a);
		int s1;
		int s2;
		for(int j=0; j<a; j++) {
			scanf("%d", &s2);
			if (j != 0) {
				graph[s1].push_back(s2);
				s1 = s2;
				startnode[s2]++;
			}
			else {
				s1 = s2;
			}
		}
	}	
	
	//printgraph();

	for(int i=1; i<=N; i++) {
		if (startnode[i] == 0) {
			q.push(i);
		}
	}
	
	vector<int> ans;
	
	while(!q.empty()) {
		int currnode = q.front();
		q.pop();
		ans.push_back(currnode);
		
		for(int i=0; i<graph[currnode].size(); i++) {
			int nextnode = graph[currnode][i];
			startnode[nextnode]--;
			if (startnode[nextnode] == 0) {
				q.push(nextnode);
			}
		}
		
		//printstartnode();
		
	}
	
	for(int i=1; i<=N; i++) {
		if (startnode[i] != 0) {
			printf("0\n");
			return 0;
		}
	}
	
	for(int i=0; i<ans.size(); i++) {
		printf("%d\n", ans[i]);
	}
	
	
	
	
}
