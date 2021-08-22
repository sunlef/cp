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
char s[MAXN];
void solve() {
    cin >> s;
    int n = strlen(s);
    for (int i = 0; i < n - 1; ++i)
        if (s[i] == 'A' && s[i + 1] == 'B')
            for (int j = i + 2; j < n - 1; ++j)
                if (s[j] == 'B' && s[j + 1] == 'A') {
                    cout << "YES" << endl;
                    return;
                }
    for (int i = 0; i < n - 1; ++i)
        if (s[i] == 'B' && s[i + 1] == 'A')
            for (int j = i + 2; j < n - 1; ++j)
                if (s[j] == 'A' && s[j + 1] == 'B') {
                    cout << "YES" << endl;
                    return;
                }
    cout << "NO" << endl;
}
int main() {
    SYNC;

    solve();
    return 0;
}