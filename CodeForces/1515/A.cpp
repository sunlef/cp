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
const int MAXN = 114;
int n, x;
int w[MAXN];
int pre[MAXN];
void solve() {
    pre[0] = 0;
    cin >> n >> x;
    int flag = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
        pre[i] = pre[i - 1] + w[i];
        if (!flag && pre[i] == x)
            flag = i;
    }
    if (!flag) {
        cout << "YES" << endl;
        for (int i = 1; i <= n; ++i)
            cout << w[i] << " ";
        cout << endl;
    }
    if (flag) {
        if (flag == n) {
            cout << "NO" << endl;
            return;
        }
        swap(w[flag], w[flag + 1]);
        cout << "YES" << endl;
        for (int i = 1; i <= n; ++i)
            cout << w[i] << " ";
        cout << endl;
    }
}
int main() {
    SYNC;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}