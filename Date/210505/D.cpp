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
    bool operator<(const Node B) const { return d > B.d; }
} u;
priority_queue<Node> q;
void solve() {
    cin >> n >> k;
    cin >> s;
    int last = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a') {
            if (last != -1 && i - last > 1) {
                u.l = last;
                u.r = i;
                u.d = i - last - 1;
                q.push(u);
            }
            last = i;
        }
    }
    while (!q.empty()) {
        u = q.top();
        
    }
}
int main() {
    SYNC;

    solve();
    return 0;
}