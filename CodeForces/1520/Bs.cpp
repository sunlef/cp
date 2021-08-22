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
void solve() {
    int n;
    cin >> n;
    int m = n, ct = 0, ans = 0;
    while (m) {
        ct++;
        m /= 10;
    }
    ans = 9 * (ct - 1);
    string s = to_string(n);
    bool f = 1;
    for (int i = 0; i <= s.length() - 1; ++i)
        if (s[i] < s[0]) {
            f = 0;
            break;
        }
    ans += s[0] - '0';
    ans -= f == 0;
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