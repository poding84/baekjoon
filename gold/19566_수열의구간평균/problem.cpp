#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

int main() {
    long long int N, K;
    long long int sum = 0;
    vector<long long int> v;
    v.push_back(0);
    scanf("%lld %lld", &N, &K);
    for(long long int i=0; i<N; i++) {
        long long int a;
        scanf("%lld", &a);
        sum += (a-K);
        v.push_back(sum);
    }


    sort(v.begin(), v.end());

    long long int start = 0;
    long long int ans = 0;
    long long int count = 0;

    for(long long int i=0; i<=N; i++) {
        if (i == 0) {
            start = v[i];
            count = 1;
        } else {
            if (v[i] != start) {
                ans += ((count * (count-1)) / 2);
                count = 1;
                start = v[i];
            } else {
                count++;
            }
        }
    }

    ans += ((count * (count-1)) / 2);

    printf("%lld", ans);
}
