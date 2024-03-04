#include <cstdio>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int primeCount[100010];


int main() {
    long long int n;
    scanf("%lld", &n);
    if (n == 1) {
        printf("1");
        return 0;
    }

    long long int num = n;
    for(long long int i = 2; i <= n; i++) {
        while (n%i == 0 && n > 1) {
            n = n/i;
            primeCount[i]++;
        }
    }

    long long int ans = 1;
    for(int i=2; i<num; i++) {
        ans = ans * (primeCount[i] + 1);
    }

    printf("%lld", num - ans);
}
