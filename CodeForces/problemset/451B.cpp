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
    int n;
    int a[MAXN];
    int b[MAXN];
    map<int, int> ls;
    int l, r;
    void solve() {
        n = read();
        for (int i = 1; i <= n; ++i)
            a[i] = b[i] = read();
        sort(b + 1, b + n + 1);
        for (int i = 1; i <= n; ++i)
            ls[b[i]] = i;
        for (int i = 1; i <= n; ++i)
            a[i] = ls[a[i]];
        for (int i = 1; i <= n; ++i)
            if (a[i] != i) {
                l = i;
                break;
            }
        for (int i = n; i >= 1; --i)
            if (a[i] != i) {
                r = i;
                break;
            }
        if (l == 0 && r == 0) {
            cout << "yes" << endl;
            cout << 1 << " " << 1 << endl;
            return;
        }
        reverse(a + l, a + r + 1);
        for (int i = l; i <= n; ++i)
            if (a[i] != i) {
                cout << "no" << endl;
                return;
            }
        cout << "yes" << endl;
        cout << l << " " << r << endl;
    }
    int main() {
        SYNC;

        solve();
        return 0;
    }