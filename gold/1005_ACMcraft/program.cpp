#include <stdio.h> 
#include <vector>
#include <utility>
#include <queue>
#include <string.h>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

int N, K;

int building[1010];
int buildTime[1010];
vector<int> priorBuilding[1010];

int getTime(int x) {
	if (priorBuilding[x].size() == 0) {
		return building[x];
	}
	
	if (buildTime[x] != -1) {
		return buildTime[x];
	}
	
	else {
		vector<int> v;
		for(int i=0; i<priorBuilding[x].size(); i++) {
			v.push_back(getTime(priorBuilding[x][i]));
		}
		
		int max = -1;
		for(int i=0; i<v.size(); i++) {
			if (max < v[i]) {
				max = v[i];
			}
		}
		buildTime[x] = max + building[x];
		return max + building[x] ;
		
	}
}

int solve() {
	for(int i=0; i<N; i++) {
		scanf("%d", &building[i+1]);
		buildTime[i+1] = -1;
		priorBuilding[i+1].clear();
	}
	
	for(int i=0; i<K; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		priorBuilding[b].push_back(a);
	}
	int W;
	scanf("%d", &W);
	
	
	
	
	return getTime(W);
}



int main() {
	int x;
	
	scanf("%d", &x);
	for(int i=0; i<x; i++) {
		int a, b;
		scanf("%d %d", &N, &K);
		printf("%d\n", solve());
	}
	

}