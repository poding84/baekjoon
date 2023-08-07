#include <stdio.h> 
#include <vector>
#include <utility>
#include <queue>
#include <math.h>


using namespace std;

vector<pair<int, int> > v;
int N;
long long mini;
void combi(vector<int> s, int r, int index, int depth) {
	if(r == 0) {
//		for(int i=0; i<s.size(); i++) {
//			printf("%d ", s[i]);
//		}
//		printf("\n");
		pair<long long, long long> vec = {0, 0};
		int idx = 0;
		for(int i=0; i<v.size(); i++) {
			if (s[idx] == i) {
				//printf("+");
				
				vec.first += v[i].first;
				vec.second += v[i].second;
				
				idx ++;
			}
			else {
				vec.first -= v[i].first;
				vec.second -= v[i].second;
				//printf("-");
			}
		}
		long long ans = vec.first*vec.first + vec.second*vec.second;
		if (ans < mini) {
			mini = ans;
		}
		//printf("\n");
		
	}
	else if (depth == N) {
		return;
	}
	
	else {
		s[index] = depth;
        combi(s, r - 1, index + 1, depth + 1);
        combi(s, r, index, depth + 1);
		
	}
	
	
	
	
	
}


double solveProblem() {
	
	
	scanf("%d", &N);
	v.clear();
	mini = 9e10;
	
	
	for(int i=0; i<N; i++) {
		int a, b;
		scanf("%d %d", &a, &b );
		v.push_back({a, b});
	}
	
	vector<int> s(N/2);
	combi(s, N/2, 0, 0);
	
	
	return sqrt(double(mini));
}

int main() {
	
	
	int x;
	
	scanf("%d", &x);
	
	for(int i=0; i<x; i++) {
		printf("%.10lf\n", solveProblem());
	}
	
	
}
