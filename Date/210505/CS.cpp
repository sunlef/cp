typedef long long LL;
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

bool ok[1145140];
int main() {
    memset(ok, 1, sizeof ok);
    int n, k;
    scanf("%d%d", &n, &k);
    map<int, int> mp;
    LL res = 0;
    for (int i = -n; i <= n; i++)
        for (int j = -n; j <= n; j++) {
            int t = i * (i + 1) + j * (j + 1);
            mp[t]++;
        }
    //  for (int i = -n; i <= n; i++) {
    //      cout << mp[i] << " ";
    //  }
    for (int i = -n; i <= n; i++) {
        for (int j = -n; j <= n; j++) {
            int x = i * (i + 1) + j * (j + 1);
            if (ok[x]) {
                res += mp[x] * mp[x * k];
            }
            ok[x] = false;
        }
    }
    cout << res << endl;
}