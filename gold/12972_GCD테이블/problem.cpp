#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define clr(x) memset(x, 0, sizeof(x))
#define whileT int T; cin >> T; while(T--)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;


priority_queue<int> pq_table;
priority_queue<int> pq_list;

int arr[510];



int gcd(int x, int y) {
	if (x == 0) {
		return y;
	} else if(y == 0) {
		return x;
	}
	
	
	if (x > y) {
		return gcd(x%y, y);
	} else {
		return gcd(x, y%x);
	}

}


int main() {
	int n;
	scanf("%d", &n);
	
	for(int i=0; i<n*n; i++) {
		int a;
		scanf("%d", &a);
		pq_table.push(a);
	}
	
	for(int i=0; i<n; i++) {
		int table_max = pq_table.top();
		pq_table.pop();
		
		while(!pq_list.empty()) {
			int max = pq_list.top();
			if (max == table_max) {
				pq_list.pop();
				table_max = pq_table.top();
				pq_table.pop();
			} else {
				break;
			}
		}
		
		
		arr[i] = table_max;
		//printf("\n%d\n-----\n", table_max);
		for(int j=0; j<i; j++) {
			int temp;
			temp = gcd(arr[j], table_max);
			pq_list.push(temp);
			pq_list.push(temp);
		//	printf("%d ", temp);
		}
		// printf("--------\n");
		
	}
	
	for(int i=0; i<n; i++) {
		printf("%d ", arr[i]);
	}
	
}
