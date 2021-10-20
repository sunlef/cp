//我好像只会暴力遍历。。。
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
const int maxn = 1e9 + 10;
long long n;
long long k;

int main() {
    int test;
    scanf("%d", &test);
    while (test--) {
        scanf("%lld %lld", &n, &k);
        //从1开始进行遍历么？
        if (k >= n) {  //大了就直接输出
            printf("1\n");
        } else {
            long long i;
            long long ans = 0x3f3f3f3f;
            //不必遍历所有的因子，只需要遍历根号个就可以了，枚举的是内容的多少
            for (i = 1; i * i <= n; i++) {
                //如果能够整除并且小于
                if (n % i == 0) {
                    if (i <= k) {
                        ans = min((n / i), ans);
                    } else {
                        //直接break
                        break;
                    }
                    if ((n / i) <= k) {
                        ans = min(ans, i);
                    }
                }
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}
