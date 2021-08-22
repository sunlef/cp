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
const int MAXN = 10514;
int N;
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
vector<int> G[MAXN];
int ru[MAXN], chu[MAXN];
int maxn;
vector<int> ans, tmp;
void dfs(int u, int step) {
    if (step > maxn) {
        maxn = step;
        ans = tmp;
    } else if (step == maxn && tmp < ans)
        ans = tmp;
    for (auto v : G[u]) {
        tmp.push_back(v);
        dfs(v, step + 1);
        tmp.pop_back();
    }
}
void solve() {
    N = read();
    maxn = -INF;
    for (int i = 0; i < N; ++i) {
        int k = read();
        while (k--) {
            int u = read();
            ru[u]++;
            chu[i]++;
            G[i].push_back(u);
        }
    }
    int root = 0;
    while (ru[root])
        ++root;
    ans.push_back(root);
    dfs(root, 1);
    cout << ans.size() + 1 << endl;
    cout << root;
    for (auto i : ans)
        cout << " " << i;
    cout << endl;
}
int main() {
    SYNC;

    solve();
    return 0;
}