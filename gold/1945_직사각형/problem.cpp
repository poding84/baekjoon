#include <stdio.h> 
#include <queue>
#include <utility>

using namespace std;


priority_queue<pair<double, int>> pq;


int main() {
	int n;
	scanf("%d", &n);
	
	for(int i=0; i<n; i++) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		double x, y;
		x = (double)b/(double)c; // 1
		y = (double)d/(double)a; // 3
		pq.push({-x, 1});
		pq.push({-y, -1});
	}
	
	int sum = 0;
	int min = -1;
	int max = 1;
	
	while (!pq.empty()) {
		//printf("%f %d\n", pq.top().first, pq.top().second);
		sum += pq.top().second;
		if (sum < min) {
			min = sum;
		}
		
		if (sum > max) {
			max = sum;
		}
		pq.pop();
		
	}
	if(max > -min) {
		printf("%d", max);
	} else {
			printf("%d", -min);

	}
	
}
