#include <stdio.h> 
#include <vector>
#include <utility>
#include <queue>
#include <string.h>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

int V, E;

priority_queue<pair<int, pair<int, int> > > q;

int mom[10010];

int getMom(int x) {
	if (mom[x] == 0) {
		return x;
	}
	mom[x] = getMom(mom[x]);
	
	return mom[x];
	
	
}


int main() {
	
	scanf("%d %d", &V, &E);
	
	for(int i=0; i<E; i++) {
		int a, b, c;
		
		scanf("%d %d %d", &a, &b, &c);
		
		q.push({-c, {a, b}});		
	}
	int tot = 0;
	int num = 0;
	while(!q.empty() && num < V-1) {
		int dist = -q.top().first;
		int a = q.top().second.first;
		int b = q.top().second.second;
		
		q.pop();
		//printf("%d %d %d\n", dist, a, b);
		int moma = getMom(a);
		int momb = getMom(b);
		if (moma != momb) {
			mom[moma] = momb;
			tot += dist;
			num ++;
		}
	}
	
	printf("%d", tot);

}