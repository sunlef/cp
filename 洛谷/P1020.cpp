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
int a[MAXN];
int cnt;
int dp1[MAXN];
int dp2[MAXN];
int len1, len2;
void solve() {
    dp1[1] = dp2[1] = a[1];
    len1 = len2 = 1;
    for (int i = 2; i <= cnt; ++i) {
        if (a[i] <= dp1[len1])
            dp1[++len1] = a[i];
        else {
            int pos =
                upper_bound(dp1 + 1, dp1 + len1 + 1, a[i], greater<int>()) -
                dp1;
            dp1[pos] = a[i];
        }
        if (a[i] > dp2[len2])
            dp2[++len2] = a[i];
        else {
            int pos = lower_bound(dp2 + 1, dp2 + len2 + 1, a[i]) - dp2;
            dp2[pos] = a[i];
        }
    }
    cout << len1 << endl << len2 << endl;
}
int main() {
    SYNC;
    int t;
    while (cin >> t)
        a[++cnt] = t;
    solve();
    return 0;
}