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
string s;
bool flag[30];
void solve() {
    cin >> n >> s;
    memset(flag, false, sizeof(flag));
    for (int i = 0; i < n; ++i) {
        if (flag[s[i] - 'A'] && i > 0 && s[i - 1] != s[i]) {
            cout << "NO" << endl;
            return;
        }
        flag[s[i] - 'A'] = true;
    }
    cout << "YES" << endl;
}
int main() {
    SYNC;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}