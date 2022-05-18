#include <bits/stdc++.h>

using namespace std;

char a[1010];
char b[1010];

int dp[1010][1010];

pair<int, string> getLCS(int ea, int eb) {
	string s;
	if (ea == 0) {
		if (eb == 0) {
			if (a[ea] == b[eb]) {
				s += a[ea];
				return {1, s};
			}
			return {0, ""};
		}
		else {
			
			for(int i=eb; i>=0; i--) {
				if (b[i] == a[ea]) {
					s += a[ea];
					return {1, s};
				}
			}
			return {0, ""};
		}
		
		
	}
	
	if (eb == 0) {
		if (ea == 0) {
			if (a[ea] == b[eb]) {
				s += a[ea];
				return {1, s};
			}
			return {0, ""};
		}
		else {
			
			for(int i=ea; i>=0; i--) {
				if (a[i] == b[eb]) {
					s += b[eb];
					return {1, s};
				}
			}
			return {0, ""};
		}
		
		
	}
	
	return {5, "asdf"};
	
	
}


int main() {
	
	scanf("%s", a);
	scanf("%s", b);
	
	
	pair<int, string> p = getLCS(strlen(a)-1, strlen(b)-1);
	printf("%d\n%s", p.first, p.second.c_str());
	
}
