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
const int MAXN = 214514;
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
int n, l, r;
int a[MAXN], b[MAXN];
int cntl[MAXN], cntr[MAXN];
int ans;
void solve() {
    n = read();
    l = read();
    r = read();
    for (int i = 1; i <= n; ++i)
        cntl[i] = cntr[i] = 0;
    for (int i = 1; i <= l; ++i) {
        a[i] = read();
        cntl[a[i]]++;
    }
    for (int i = 1; i <= r; ++i) {
        b[i] = read();
        cntr[b[i]]++;
    }
    for (int i = 1; i <= n; ++i) {
        int lo = min(cntl[i], cntr[i]);
        cntl[i] -= lo;
        cntr[i] -= lo;
        l -= lo;
        r -= lo;
    }
    ans = 0;
    if (l > r) {
        for (int i = 1; i <= n; ++i) {
            while (l != r && cntl[i] >= 2) {
                l -= 2;
                cntl[i] -= 2;
                ++ans;
            }
            if (l == r)
                break;
        }
        ans += l;
    } else {
        for (int i = 1; i <= n; ++i) {
            while (l != r && cntr[i] >= 2) {
                r -= 2;
                cntr[i] -= 2;
                ++ans;
            }
            if (l == r)
                break;
        }
        ans += r;
    }
    cout << ans << endl;
}
int main() {
    SYNC;
    int t = read();
    while (t--)
        solve();
    return 0;
}