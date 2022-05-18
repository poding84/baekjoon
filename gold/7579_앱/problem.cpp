#include <stdio.h>
#include <utility>

using namespace std;

int appNum, totMem;


int appMem[110];
int appCost[110];

int memcost[10010];

int max(int x, int y) {
	return x>y ? x : y;
}

void printmemcost() {
	for(int i=0; i<=100; i++) {
		printf("%d ", memcost[i]);
	}
	printf("\n");
}

int main() {
	
	scanf("%d %d", &appNum, &totMem);
	
	
	for(int i=0; i<appNum; i++) {
		scanf("%d", &appMem[i]);
	}
	
	for(int i=0; i<appNum; i++) {
		scanf("%d", &appCost[i]);
	}
	//printmemcost();
	
	for(int i=0; i<appNum; i++) {
		int mem = appMem[i];
		int cost = appCost[i];
		
		for(int j=10000; j>=cost+1; j--) {
			memcost[j] = max(memcost[j], memcost[j-cost] + mem);
		}
		memcost[cost] = max(memcost[cost], mem);
		//printmemcost();
	}
	
	for(int i=0; i<=10000; i++) {
		if (memcost[i] >= totMem) {
			printf("%d", i);
			return 0;
		}
	}
	
	
	
	
}
