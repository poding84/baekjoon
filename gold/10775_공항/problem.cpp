#include <stdio.h> 
#include <vector>
#include <utility>
#include <queue>
#include <string.h>
#include <map>
#include <math.h>
#include <set>

using namespace std;




int main(){
	
	int g, p;
	scanf("%d", &g);
	scanf("%d", &p);
	
	set<int> s;
	
	for(int i=1; i<=g; i++) {
		s.insert(-i);
	}
	 
	
	bool flag = false;
	int cnt = 0;
	for(int i=0; i<p; i++) {
		int a;
		scanf("%d", &a);
		auto it = s.lower_bound(-a);
		if (it == s.end()) {
			flag = true;
		}
		
		if (flag) {
			continue;
		}
		cnt++;
		s.erase(it);
		//a���� ũ�� �����鼭 ���� �Ⱦ� �ڸ��� ����. 
		
	}
	printf("%d", cnt);
	
}
