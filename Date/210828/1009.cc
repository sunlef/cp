#include <bits/stdc++.h>
using namespace std;
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define ch(a) (int(a - 'a') + 1)
#define chh(a) (int(a - 'A') + 1)
#define mm(a) memset(a, 0, sizeof(a))
#define Erica_1031 Errrica 'u'
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define inf 0x7FFFFFFF
#define sset                           \
    set<int>::iterator it = a.begin(); \
    it !=.end();                       \
    ++it
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
const int Maxx = 1e5 + 99;
long long mod = 1000000007;
char s[Maxx];
int sumh[Maxx];
int sums[Maxx];
int sh, ss;
int n;
ll ans;
void solve() {
    scanf("%d", &n);
    scanf("%s", s + 1);
    sumh[0] = 0, sums[0] = 0;
    sh = 0, ss = 0, ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 'U')
            sumh[i] = sumh[i - 1], sums[i] = sums[i - 1] + 1;
        else if (s[i] == 'D')
            sumh[i] = sumh[i - 1], sums[i] = sums[i - 1] - 1;
        else if (s[i] == 'L')
            sumh[i] = sumh[i - 1] - 1, sums[i] = sums[i - 1];
        else
            sumh[i] = sumh[i - 1] + 1, sums[i] = sums[i - 1];
    }
    for (int i = 2; i <= n; i += 2) {
        for (int j = 1; j + i - 1 <= n; ++j) {
            sh = sumh[j + i - 1] - sumh[j - 1];
            ss = sums[j + i - 1] - sums[j - 1];
            if (!sh && !ss) ++ans;
        }
    }
    printf("%lld\n", ans);
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}