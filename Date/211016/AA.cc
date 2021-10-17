#include <bits/stdc++.h>
using namespace std;
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define ch(a) (int(a - '0'))
#define chh(a) (int(a - 'A') + 1)
#define mm(a) memset(a, 0, sizeof(a))
#define Erica_1031 Errrica 'u'
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define inf 0x7FFFFFFF
#define odd(n) (n & 1)
#define even(n) (!(n & 1))
#define sset                              \
    set<int>::iterator it = a[i].begin(); \
    it != a[i].end();                     \
    ++it
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
const int Maxx = 4 * 1e5 + 99;
long long mod = 1e9 + 7;
int n, k;
int main() {
    scanf("%d%d", &n, &k);
    if (n % (k + 1))
        printf("Adrien\n");
    else
        printf("Austin\n");
    return 0;
}
