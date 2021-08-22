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
#define __qReadType int
inline __qReadType read() {
    __qReadType x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = 10 * x + ch - '0';
        ch = getchar();
    }
    return f * x;
}
int n, m, x;
struct Node {
    int h, idx;
    bool operator<(const Node B) const { return h < B.h; }
} a[MAXN];
int h[MAXN];
int ans[MAXN];
void solve() {
    n = read();
    m = read();
    x = read();
    for (int i = 1; i <= n; ++i) {
        a[i].h = read();
        a[i].idx = i;
    }
    sort(a + 1, a + n + 1);
    int pos = 0;
    for (int i = 1; i <= n; ++i) {
        ans[a[i].idx] = ++pos;
        if (pos == m)
            pos = 0;
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    cout << endl;
}
int main() {
    SYNC;
    int t = read();
    while (t--)
        solve();
    return 0;
}