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
int n;
int m[MAXN][MAXN];
void solve() {
    cin >> n;
    if(n == 1) {
        cout << 1 << endl;
        return;
    }
    if(n == 2) {
        cout << -1 << endl;
        return;
    }
    int now1 = 1, now2 = n * n / 2 + 1;
    if(n & 1)
        ++now2;
    bool flag = false;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j) {
            if(!flag)
                m[i][j] = now1++;
            else
                m[i][j] = now2++;
            flag = !flag;
        }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j)
            cout << m[i][j] << " ";
        cout << endl;
    }
}
int main() {
    SYNC;
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}