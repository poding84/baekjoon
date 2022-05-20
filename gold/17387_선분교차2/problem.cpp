#include <stdio.h> 
#include <vector>
#include <utility>
#include <queue>

using namespace std;

long long ccw(pair<long long, long long> p1, pair<long long, long long> p2, pair<long long, long long> p3) {
	
	long long ans = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second - p1.first * p3.second - p3.first * p2.second - p2.first * p1.second;
	
	
	return ans > 0 ? 1 : (ans == 0) ? 0 : -1;
	
}



int main() {
	long long x1, y1, x2, y2, x3, y3, x4, y4;
	
	
	scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
	
	scanf("%lld %lld %lld %lld", &x3, &y3, &x4, &y4);
	
	pair<long long, long long> p1 = {x1, y1};
	pair<long long, long long> p2 = {x2, y2};
	pair<long long, long long> p3 = {x3, y3};
	pair<long long, long long> p4 = {x4, y4};
	
	long long a, b, c, d;
	
	a = ccw(p1, p2, p3);
	b = ccw(p1, p2, p4);
	c = ccw(p3, p4, p1);
	d = ccw(p3, p4, p2);
	
	
	
	//printf("%lld %lld %lld %lld\n", a, b, c, d);
	
	int ans = 0;
	
	if (a*b < 0 && c*d<0) {
		ans = 1;
	}
	
	if (a * b == 0 && c * d < 0) {
		ans = 1;
	}
	
	if (c * d == 0 && a * b < 0) {
		ans = 1;
	}
	
	if (a * b == 0 && c * d == 0) {
		long long l1, l2, s1, s2;
		
		if (x1 != x2) {
			l1 = max(x1, x2);
			s1 = min(x1, x2);
			l2 = max(x3, x4);
			s2 = min(x3, x4);
		}
		else {
			l1 = max(y1, y2);
			s1 = min(y1, y2);
			l2 = max(y3, y4);
			s2 = min(y3, y4);
		}
		
		if (s1 <= l2 && s2 <= l1) {
			ans = 1;
		} 
		
		if (s2 <= l1 && s1 <= l2) {
			ans = 1;
		} 
		
		
		
	}
	
	
	
	
	
	printf("%d", ans);
	
}
