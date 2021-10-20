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
const int MAXN = 204514;
bool iscat[MAXN];
vector<int> G[MAXN];
bool visted[MAXN];
int degree[MAXN];
int n, m;
int ans;
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
void dfs(int u, int cat) {
    visted[u] = true;
    if (iscat[u]) {
        ++cat;
        if (cat > m)
            return;
    } else
        cat = 0;
    if (degree[u] == 1 && u != 1)
        ++ans;
    for (auto v : G[u]) {
        if (!visted[v])
            dfs(v, cat);
    }
}
void solve() {
    n = read();
    m = read();
    for (int i = 1; i <= n; ++i)
        iscat[i] = read();
    for (int i = 1; i < n; ++i) {
        int u = read();
        int v = read();
        degree[u]++;
        degree[v]++;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    cout << ans << endl;
}
int main() {
    SYNC;

    solve();
    return 0;
}