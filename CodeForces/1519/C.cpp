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
const int MAXN = 200014;
int n;
int u[MAXN];
int cnt[MAXN];
int k;
long long pre[MAXN];
long long ans[MAXN];
void solve() {
    vector<int> skill[MAXN];
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cnt[i] = ans[i] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> u[i];
        cnt[u[i]]++;
    }
    int sk;
    for (int i = 1; i <= n; ++i) {
        cin >> sk;
        skill[u[i]].push_back(sk);
    }
    for (int i = 1; i <= n; ++i) {
        if (cnt[i]) {
            sort(skill[i].begin(), skill[i].end(), greater<int>());
            for (int j = 1; j <= cnt[i]; ++j)
                pre[j] = skill[i][j - 1] + pre[j - 1];
            for (int k = 1; k <= n; ++k) {
                ans[k] += pre[(int)(cnt[i] / k) * k];
            }
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    cout << endl;
}
int main() {
    SYNC;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
