#include <stdio.h> 
#include <vector>
#include <utility>
#include <queue>
#include <string.h>
#include <map>
#include <math.h>

using namespace std;

int A[1010];
int B[1010];


map<int, long long> acnt;
map<int, long long> bcnt;

void printmap(map<int, long long> m) {
	
	for(auto iter = m.begin(); iter != m.end(); iter++) {
		int a = iter->first;
		int b = iter->second;
		printf("%d %d\n", a, b);
	}
	return;
}


int main() {
	
	int T;
	
	int n, m;
	
	scanf("%d", &T);
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		int a;
		scanf("%d", &a);
		if (i == 0) {
			A[i] = a;
		}
		else {
			A[i] = A[i-1] + a;
		}
		acnt[A[i]]++;
		for(int j=0; j<i; j++) {
			acnt[A[i]-A[j]]++;
		}
		
		
	}
	
	scanf("%d", &m);
	for(int i=0; i<m; i++) {
		int b;
		scanf("%d", &b);
		if (i == 0) {
			B[i] = b;
		}
		else {
			B[i] = B[i-1] + b;
		}
		
		bcnt[B[i]]++;
		for(int j=0; j<i; j++) {
			bcnt[B[i]-B[j]]++;
		}
		
	}
	
	long long ans=0;
	
	for(auto iter = acnt.begin(); iter != acnt.end(); iter++) {
		int a = iter->first;
		long long b = iter->second;
		
		if (bcnt.find(T-a) != bcnt.end()) {
			ans += bcnt[T-a] * b;
		}
		
		
	
	}
	
//	printmap(acnt);
//	printf("-----\n");
//	printmap(bcnt);
	
	printf("%lld", ans);
	
	
	
}
