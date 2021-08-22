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
int n;
bool gen(int len, int step, int x) {
    int res = 0;
    for (int i = 1; i <= len; ++i)
        res = 10 * res + step;
    return x >= res;
}
void solve() {
    cin >> n;
    if (n >= 0 && n <= 9) {
        cout << n << endl;
        return;
    }
    int _n = n;
    int len = 0;
    while (_n) {
        ++len;
        _n /= 10;
    }
    int ans = (len - 1) * 9;
    for (int i = 1; i <= 9; ++i) {
        if (gen(len, i, n))
            ++ans;
        else
            break;
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