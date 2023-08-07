#include <stdio.h> 
#include <vector>
#include <algorithm>


using namespace std;

vector<int> sub[55];


int howlong(int curr) {

	if (sub[curr].size() == 0) {
		return 0;
	}
	
	int temp[55];
	
	for(int i=0; i<sub[curr].size(); i++) {
		temp[i] = (howlong(sub[curr][i]));
	}
	
	sort(temp, temp+sub[curr].size());
//	printf("%d\n", curr);
//	for(int i=0; i<sub[curr].size(); i++) {
//		printf("%d ", temp[i]);
//	}
//	printf("--------------\n");
	int max = -1;
	
	for(int i=0; i<sub[curr].size(); i++) {
		int a = sub[curr].size()-i + temp[i];
		if (max < a) {
			max = a;
		}
	}
	
	
	return max;
}



int main() {
	
	
	int n; 
	
	scanf("%d", &n);
	
	for(int i=0; i<n; i++) {

		int t;
		scanf("%d", &t);
		if (i==0) {
			continue;
		}
		sub[t].push_back(i);
	}

	
	printf("%d", howlong(0));
}
