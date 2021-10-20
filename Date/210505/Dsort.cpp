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
int n, k;
string s;
struct Node {
    int l, r, d;
    bool operator<(const Node B) const { return d < B.d; }
} u;
vector<Node> v;
void solve() {
    cin >> n >> k;
    cin >> s;
    int last = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a') {
            if (i - last > 1) {
                u.l = last;
                u.r = i;
                u.d = i - last - 1;
                v.push_back(u);
            }
            last = i;
        }
    }
    u.l = last;
    u.r = n;
    u.d = n - last - 1;
    v.push_back(u);
    sort(v.begin(), v.end());
    /*  for (auto i : v) {
          cout << i.l << " " << i.r << " " << i.d << endl;
      }*/
    for (auto i : v) {
        if (i.l == -1 || i.r == n)
            continue;
        if (!k)
            break;
        if (i.l == -1) {
            for (int j = i.r - 1; j > i.l; --j) {
                if (!k)
                    break;
                s[j] = 'a';
                --k;
            }
        } else {
            for (int j = i.l + 1; j < i.r; ++j) {
                if (!k)
                    break;
                s[j] = 'a';
                --k;
            }
        }
    }
    for (auto i : v) {
        if (i.l != -1 && i.r != n)
            continue;
        if (!k)
            break;
        if (i.l == -1) {
            for (int j = i.r - 1; j > i.l; --j) {
                if (!k)
                    break;
                s[j] = 'a';
                --k;
            }
        } else {
            for (int j = i.l + 1; j < i.r; ++j) {
                if (!k)
                    break;
                s[j] = 'a';
                --k;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i < n; ++i)
        if (s[i] == 'a' && s[i - 1] == 'a')
            ++ans;
    cout << ans << endl << s << endl;
}
int main() {
    SYNC;
    solve();
    return 0;
}