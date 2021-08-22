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
//#define endl '\n'
using namespace std;
const int MAXN = 114514;
int n, t;
int k;
void solve() {
    cin >> n >> t;
    cin >> k;
    int l = 1, r = n + 1;
    int ans = -1;
    int re;
    while (l <= r) {
        int mid = l + (r - l >> 1);
        cout << "? 1 " << mid << endl;
        cin >> re;
        if (re <= mid - k) {
            ans = mid;
            r  = mid - 1;
        } else
            l = mid + 1;
    }
    cout << "! " << ans << endl;
}
int main() {
    SYNC;

    solve();
    return 0;
}