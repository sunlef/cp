//记得乘1ll
// fixed别变成珂学计数
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define SYNC ios::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define EPS 1e-6
#define endl '\n'
using namespace std;
const int MAXN = 114514;
int n, k;
set<long long> s;
void solve() {
    long long n, k;
    // cin >> n >> k;
    for (n = 1; n <= 10; ++n) {
        cout << n << ": ";
        for (k = 1; k <= 10; ++k) {
            long long ans = 0;
            for (long long x2 = -n; x2 <= n; ++x2)
                for (long long x3 = -n; x3 <= n; ++x3)
                    for (long long x4 = -n; x4 <= n; ++x4)
                        for (long long x1 = -n; x1 <= n; ++x1)
                            if (x1 * (x1 + 1) + x2 * (x2 + 1) ==
                                k * (x3 * (x3 + 1) + x4 * (x4 + 1)))
                                ++ans;
            cout << ans << " ";
        }
        cout << endl;
    }
}
int main() {
    SYNC;
    freopen("dabiao.txt", "w", stdout);
    solve();
    return 0;
}