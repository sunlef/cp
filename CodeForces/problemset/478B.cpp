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
int n, m;
void solve() {
    cin >> n >> m;
    int _n = n;
    long long ans = 0;
    int lo = n / m;
    int cnt = n % m;
    ans +=
        1ll * cnt * (lo + 1ll) * lo / 2 + (1ll * m - cnt) * lo * (lo - 1ll) / 2;
    cout << ans << " ";
    ans = 0;
    _n = n - m + 1;
    ans = 1ll * _n * (_n - 1) / 2;
    cout << ans << endl;
}
int main() {
    SYNC;

    solve();
    return 0;
}