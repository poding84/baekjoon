#include <stdio.h> 
#include <vector>
#include <utility>
#include <queue>
#include <string.h>

using namespace std;

bool dp[210][210];


int main() {
	int n;
	scanf("%d", &n);
	
	for(int num=0; num<n; num++) {
		char str1[1010];
		char str2[1010];
		char str3[1010];
		int len1;
		int len2;
		int totlen;
		
		scanf("%s %s %s", str1, str2, str3);
		
		len1 = strlen(str1);
		len2 = strlen(str2);
		totlen = strlen(str3);
		
		
		queue<pair<int, int> > q;
		
		for(int i=0; i<205; i++) {
			for(int j=0; j<205; j++) {
				dp[i][j]=false;
			}
		}
		
		q.push(make_pair(0, 0));
		
		while(!q.empty()) {
			int one = q.front().first;
			int two = q.front().second;
			int three = one + two;
			
			q.pop();
			
			if (dp[one][two]) {
				continue;
			}
			
			if (dp[len1][len2]) {
				break;
			}
			//printf("%d %d\n", one, two);
			dp[one][two] = true;
			
			
			
			if (len1 == one) {
				if (str2[two] == str3[three]) {
					q.push(make_pair(one, two+1));
				}
			} else if (len2 == two) {
				if (str1[one] == str3[three]) {
					q.push(make_pair(one+1, two));
				}
				
			} else {
				if(str1[one] == str2[two]) {
					if (str1[one] == str3[three]) {
						q.push(make_pair(one+1, two));
						q.push(make_pair(one, two+1));
					}
					
				} else if(str1[one] == str3[three]) {
					q.push(make_pair(one+1, two));
					
				} else if (str2[two] == str3[three]) {
					q.push(make_pair(one, two+1));
				}
				
			}
			
		}		
		if (dp[len1][len2]) {
			printf("Data set %d: yes\n", num+1 );
		}
		else {
			printf("Data set %d: no\n", num+1 );
		}
		
	}
	
}