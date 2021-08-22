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
void solve() {
    cin >> n >> k;
    if (k >= n) {
        cout << 1 << endl;
        return;
    }
    long long ans = INF;
    for (long long i = 1; i <= k && i * i <= n; ++i) {
        if (n % i == 0) {
            ans = min(ans, n / i);
            if (n / i <= k)
                ans = min(ans, i);
        }
    }
    cout << ans << endl;
}
int main() {
    SYNC;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}