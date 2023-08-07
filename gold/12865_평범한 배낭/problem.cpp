#include <stdio.h>
#include <vector>
#include <utility>

using namespace std;

int N, K;

vector<pair<int, int> > stuffs; //weight, price;

int bag[100010];

void printbag() {
	for(int i=1; i<=K; i++) {
		printf("%d ", bag[i]);
	}
	printf("\n");
}

int main() {
	
	scanf("%d %d", &N, &K);
	
	for(int i=0; i<N; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		stuffs.push_back({a, b});
		
	}
	
	
	
	for(int i=0; i<N; i++) {
		int weight = stuffs[i].first;
		int price = stuffs[i].second;
		int tempbag[100010];
		//printf("%d %d\n", weight, price);
		
		
		tempbag[weight] = max(bag[weight], price);
		
		for(int i=weight+1; i<=K; i++) {
			tempbag[i] = max(bag[i-weight] + price, bag[i]);
		}
		
		for(int i=weight; i<=K; i++) {
			bag[i] = tempbag[i];
		}
		
		
		//printbag();
		
		
	}
	
	int maxx = -1;
	for(int i=1; i<=K; i++) {
		if(maxx < bag[i]) {
			maxx = bag[i];
		}
	}
	
	printf("%d", maxx);
	
	
	
	
}
