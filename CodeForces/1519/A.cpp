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
long long r, b, d;
void solve() {
    cin >> r >> b >> d;
    if (r > b) {
        if (b * (1 + d) >= r)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    } else if (b > r) {
        if (r * (1 + d) >= b)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        return;
    }
}
int main() {
    SYNC;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}