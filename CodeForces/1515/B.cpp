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
int n;
void solve() {
    cin >> n;
    if (n & 1) {
        cout << "NO" << endl;
        return;
    }
    n /= 2;
    int x = sqrt(n);
    if (x * x == n) {
        cout << "YES" << endl;
        return;
    }
    if (n % 2 == 0) {
        n /= 2;
        x = sqrt(n);
        if (x * x == n) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
    
}
int main() {
    SYNC;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}