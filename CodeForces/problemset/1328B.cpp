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
int n, k;
void solve() {
    n = read();
    k = read();
    long long now = 1;
    int u = 2;
    for (long long i = 1;; ++i) {
        if (now + i > k)
            break;
        now += i;
        ++u;
    }
    int v = k - now + 1;
    u = n - u + 1;
    v = n - v + 1;
    for (int i = 1; i <= n; ++i) {
        if (i == u || i == v)
            cout << 'b';
        else
            cout << 'a';
    }
    cout << endl;
}
int main() {
    SYNC;
    int t = read();
    while (t--)
        solve();
    return 0;
}