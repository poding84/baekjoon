#include <stdio.h> 
#include <vector>
#include <utility>
#include <queue>
#include <string.h>
#include <map>
#include <math.h>

using namespace std;

int parent[500010];

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
		int a, b;
		
		scanf("%d %d", &a, &b);
		a++;
		b++;
		
		int para = getParent(a);
		int parb = getParent(b);
		
		if (para == parb) {
			printf("%d", i+1);
			return 0;
		}
		
		parent[para] = parb;
		
	}
	
	printf("%d", 0);
	
	return 0;
}
