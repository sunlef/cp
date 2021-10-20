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
long long n, t;
long long a[MAXN];
bool check(int x, int r) {
    return a[r] - a[r - x] <= t;
}
void solve() {
    cin >> n >> t;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    int ans = 0;
    for (int i = n; i >= 1; --i) {
        int l = 1, r = i;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(mid, i)) {
                ans = max(ans, mid);
                l = mid + 1;
            } else
                r = mid - 1;
        }
    }
    cout << ans << endl;
}
int main() {
    SYNC;

    solve();
    return 0;
}