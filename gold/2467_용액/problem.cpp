#include <stdio.h>
#include <algorithm>


using namespace std;


int N;
int sol[100010];

int abs(int x) {
	return x>0 ? x : -x;
}


int main() {
	scanf("%d", &N);
	
	for(int i=0; i<N; i++) {
		scanf("%d", &sol[i]);
	}
	
	int min = 2e9+1;
	int mini1;
	int mini2;
	
	for(int i=0; i<N; i++) {
		int a = -sol[i];
		int lowerindex = lower_bound(sol, sol+N, a) - sol;
		int val;
		
		int minindex1, minindex2;
		
		if (i == lowerindex || lowerindex - 1 == i) {
			if (i == 0) {
				val = sol[0] + sol[1];
				minindex1 = 0;
				minindex2 = 1;
			}
			else if (i == N-1){
				val = sol[N-2] + sol[N-1];
				minindex1 = N-1;
				minindex2 = N-2;
			}
			else {
				int val1 = abs(sol[i-1] + sol[i]);
				int val2 = abs(sol[i] + sol[i+1]);
				if (val1<val2) {
					val = val1;
					minindex1 = i-1;
					minindex2 = i;
				}
				else {
					val = val2;
					minindex1 = i;
					minindex2 = i+1;
				}				
			}
		}
		else {
			if (lowerindex == 0) {
				val = sol[0] + sol[i];
				minindex1 = 0;
				minindex2 = i;
			}
			else if (lowerindex == N) {
				val = sol[i] + sol[N-1];
				minindex1 = i;
				minindex2 = N-1;
			}
			else {

				
				int val1 = abs(sol[lowerindex - 1] + sol[i]);
				int val2 = abs(sol[i] + sol[lowerindex]);
				if (val1<val2) {
					val = val1;
					minindex1 = lowerindex-1;
					minindex2 = i;
				}
				else {
					val = val2;
					minindex1 = i;
					minindex2 = lowerindex;
				}	
				
				if (minindex2 < minindex1) {
					int temp = minindex2;
					minindex2 = minindex1;
					minindex1 = temp;
				}
			}
		}
		
		val = abs(val);
		
		if (val < min) {
			min = val;
			mini1 = minindex1;
			mini2 = minindex2;
		}
		
	}
	
	printf("%d %d", sol[mini1], sol[mini2]);
}


