#include <stdio.h> 
#include <vector>
#include <utility>
#include <queue>
#include <string.h>
#include <map>


using namespace std;

int N, S;
int arr[50];

map<int, long long> getSubseq(int s, int e) {
	
	if (s == e) {
		map<int, long long> m;
		m[arr[s]] = 1;
		return m;
	}
	else if (e - s == 1) {
		map<int, long long> m;
		m[arr[s]] = 1;
		
		int temp = arr[s] + arr[e];
		
		if (m.find(temp) != m.end()) {
			m[temp] += 1;
		}
		else {
			m[temp] = 1;
		}
		
		temp = arr[e];
		
		if (m.find(temp) != m.end()) {
			m[temp] += 1;
		}
		else {
			m[temp] = 1;
		}
		
		
		return m;
	}
	
	
	int mid = (s+e)/2;
	
	map<int, long long> m1 = getSubseq(s, mid);
	map<int, long long> m2 = getSubseq(mid+1, e);
//	printf("sss%d %dsss\n", s, e);
	map<int, long long> m;
	bool first = true;
	for(auto iter1:m1) {
		m[iter1.first] = iter1.second;
	}
	
	for(auto iter1:m1) {
		
		for(auto iter2:m2) {
			int temp = iter1.first + iter2.first;
			m[temp] += iter1.second * iter2.second;

			
			if (first) {
				if (m.find(iter2.first) != m.end()) {
					m[iter2.first] += iter2.second;
				}
				else {
					m[iter2.first] = iter2.second;
				}
			
			}
		}
		
		
		first = false;
	}
	
	//printmap(m);
	
	return m;
	
}


int main() {
	scanf("%d %d", &N, &S);
	
	for(int i=0; i<N; i++) {
		scanf("%d", &arr[i]);
	}
	int mid = (0 + N - 1) / 2;
	if (N == 1) {
		if (arr[0] == S) {
			printf("1");
		}
		else {
			printf("0");
		}
		return 0;
	}
	map<int, long long> m1 = getSubseq(0, mid);
	map<int, long long> m2 = getSubseq(mid+1, N-1);
	
	long long cnt = 0;
	for(auto iter:m1) {
		int temp = S - iter.first;
		if (m2.find(temp) != m2.end()) {
			cnt += iter.second * m2[temp];
			//printf("%d %d : %d %d\n",iter.first, temp, iter.second, m2[temp]);
		}
		
		if (iter.first == S) {
			cnt += m1[S];
		}
	} 	 
	
	if (m2.find(S) != m2.end()) {
		cnt += m2[S];
		//printf("%d %d : %d %d\n",iter.first, temp, iter.second, m2[temp]);
	}
	
	printf("%lld", cnt);
	
	
}