#include <stdio.h>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

int N, Q;

int group[200010];
vector<int> graph[200010];
bool isStrangeNode[200010];
bool visited[200010];

int getGroup(int n) {
    if (group[n] == 0) {
        return n;
    } else {
        int g = getGroup(group[n]);
        group[n] = g;
        return g;
    }
}

bool dfs(int from, int to) {
    if (from == to) {
        isStrangeNode[from] = true;
        return true;
    }

    if (visited[from]) {
        return false;
    }
    visited[from] = true;

    for(int i=0; i<graph[from].size(); i++) {
        int nextNode = graph[from][i];
        if (dfs(nextNode, to)) {
            isStrangeNode[from] = true;
            return true;
        }
    }

    return false;
}

void setGroup(int node, int groupNum) {
    if (isStrangeNode[node] && (node != groupNum)) {
        return;
    }
    if (visited[node]) {
        return;
    }
    visited[node] = true;
    group[node] = groupNum;

    for(int i=0; i<graph[node].size(); i++) {
        setGroup(graph[node][i], groupNum);
    }
}

int main() {
    scanf("%d %d", &N, &Q);
    pair<int, int> strange;
    for(int i=0; i<N; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        int groupA = getGroup(a);
        int groupB = getGroup(b);
        if (groupA == groupB) {
            strange = make_pair(a, b);
        } else {
            graph[a].push_back(b);
            graph[b].push_back(a);
            group[groupA] = groupB;
        }
    }

    dfs(strange.first, strange.second);
    for(int i=1; i<=N; i++) {
        visited[i] = false;
    }

    for(int i=1; i<=N; i++) {
        if (isStrangeNode[i]) {
            setGroup(i, i);
        }
    }

    vector<int> ans;
    for(int i=0; i<Q; i++) {
        int p, q;
        scanf("%d %d", &p, &q);
        if (group[p] == group[q]) {
            ans.push_back(1);
        } else {
            ans.push_back(2);
        }
    }

    for(int i=0; i<Q; i++) {
        printf("%d\n", ans[i]);
    }
}