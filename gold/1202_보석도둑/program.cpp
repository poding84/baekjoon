#include <stdio.h> 
#include <vector>
#include <utility>
#include <queue>
#include <string.h>
#include <map>
#include <algorithm>
#include <set>
using namespace std;


int jewels, bags;

priority_queue<pair<int, int> > jewelList; //price, heavy;

multiset<int> bagList;



int main() {

	scanf("%d %d", &jewels, &bags);
	for(int i=0; i<jewels; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		jewelList.push({b, a});
	}
	
	for(int i=0; i<bags; i++) {
		int a;
		scanf("%d", &a);
		bagList.insert(a);
		
	}
	
	
	long long sum = 0;

	

	for(int i=0; i<bags;) {
		if (jewelList.empty()) {
			break;
		}
		int price = jewelList.top().first;
		int heavy = jewelList.top().second;
		jewelList.pop();
		multiset<int>::iterator iter = bagList.lower_bound(heavy);
		//printf("%d %d %d\n", price, heavy, *iter);
		if (iter != bagList.end()) {
			sum += price;
			bagList.erase(iter);
			i++;
		}
	}

	
	
	printf("%lld", sum);
	
	

}