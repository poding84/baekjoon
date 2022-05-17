#include <stdio.h>
#include <algorithm>

#define ll long long
using namespace std;

int N;
int sol[5010];

long long abss(long long x){
	return x>0 ? x : -x;
}

int main() {
	
	scanf("%d", &N);
	
	for(int i=0; i<N; i++) {
		scanf("%d", &sol[i]);
	}
	
	sort(sol, sol+N);
	
	
	long long minval;
	int minidx1, minidx2, minidx3;
	minval = 3e9+1;
	
	for(int i=0; i<N-1; i++) {
		for(int j=i+1; j<N; j++) {
			int num = sol[i] + sol[j];
			num *= -1;
			
			int lowerindex = lower_bound(sol, sol+N, num) - sol;
			
			int posindex1 = lowerindex - 1;
			int posindex2 = lowerindex;
			
			long long val;
			
			int idx1, idx2, idx3;
			
			if (posindex1 == j) {
				posindex1 -= 1;
			}
			
			
			if (posindex1 == i) {
				posindex1 -= 1;
			}
			
			if (posindex2 == i) {
				posindex2 += 1;
			}
			
			if (posindex2 == j) {
				posindex2 += 1;
			}
			
			if (posindex1 < 0) {
				val = (ll)sol[i] + sol[j] + sol[posindex2];
				idx1 = i;
				idx2 = j;
				idx3 = posindex2;
			}
			else if (posindex2 > N-1) {
				val = (ll)sol[i] + sol[j] + sol[posindex1];
				idx1 = i;
				idx2 = j;
				idx3 = posindex1;
			}
			else {
				long long val1 =  abss((ll)sol[i] + sol[j] + sol[posindex1]);
				long long val2 =  abss((ll)sol[i] + sol[j] + sol[posindex2]);
				if (val1 < val2) {
					val = val1;
					idx1 = i;
					idx2 = j;
					idx3 = posindex1;
				}
				else {
					val = val2;
					idx1 = i;
					idx2 = j;
					idx3 = posindex2;
				}
				
				
			}
			
			val = abss(val);
			//printf("%d %d %d %d %d\n", idx1, idx2, idx3, val, lowerindex);
			if (val < minval) {
				minval = val;
				minidx1 = idx1;
				minidx2 = idx2;
				minidx3 = idx3;
			}
			
			 
		}
	}
	
	
	if (minidx3 < minidx1) {
		printf("%d %d %d", sol[minidx3], sol[minidx1], sol[minidx2]);
	}
	else if(minidx3 < minidx2) {
		printf("%d %d %d", sol[minidx1], sol[minidx3], sol[minidx2]);
	}
	else {
		printf("%d %d %d", sol[minidx1], sol[minidx2], sol[minidx3]);
	}
	
	
	
}
