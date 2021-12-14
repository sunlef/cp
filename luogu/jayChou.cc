#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define SYNC                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
#define F(i, m, n) for (int i = m; i <= n; i++)
#define f(i, m, n) for (int i = m; i >= n; i--)
#define debug(n) \
    if (deb == 1) cout << #n << "=" << n << endl
#define deb(n) \
    if (deb == 1) cout << #n << "=" << n << "   "
#define div(ch)                                    \
    if (deb == 1) {                                \
        for (int i = 1; i <= 40; i++) cout << #ch; \
        cout << endl;                              \
    }
#define mm(A, n) memset(A, n, sizeof(A))
#define lowbit(x) (x & (-x))
#define PII pair<int, int>
#define endl '\n'
typedef long long LL;
const int maxn = 1e5 + 10;
const int maxa = 1e6 + 10;
const int mod = 1e9 + 7;
const double eps = 1e-9;
const bool deb = 1;
using namespace std;

struct type {
    int v1, v2, id;
} A[maxn], B[maxn];
int AA[maxn], BB[maxn], ans[maxn];

void oper() {
    int n;
    cin >> n;

    int max1 = -inf, max2 = -inf;
    int id1 = 0, id2 = 0;
    for (int i = 1; i <= n; i++) {
        cin >> A[i].v1, B[i].v1 = A[i].v1;
        if (A[i].v1 > max1) max1 = A[i].v1, id1 = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> A[i].v2, B[i].v2 = A[i].v2;
        if (A[i].v2 > max2) max2 = A[i].v2, id2 = i;
    }

    for (int i = 1; i <= n; i++) ans[i] = 0;
    div(11);
    sort(A + 1, A + n + 1, [&](type a, type b) -> bool { return a.v1 < b.v2; });
    div(33);
    sort(B + 1, B + n + 1, [&](type a, type b) -> bool { return a.v2 < b.v2; });
    div(22);
    for (int i = 1; i <= n; i++) AA[i] = A[i].v1, BB[i] = B[i].v2, A[i].id = i, B[i].id = i;

    int min1 = A[id2].v1, min2 = A[id1].v2;
    int ra = n, rb = n;
    ans[ra] = ans[rb] = 1;

    while (1) {
        int la = upper_bound(AA + 1, AA + n + 1, min1) - AA;
        int n2 = min2;
        for (int i = la; i < ra; i++) {
            ans[A[i].id] = 1, n2 = min(A[i].v2, n2);
        }

        int lb = upper_bound(BB + 1, BB + n + 1, min2) - BB;
        int n1 = min1;
        for (int i = lb; i < rb; i++) {
            ans[B[i].id] = 1, n1 = min(A[i].v1, n1);
        }

        if (n1 == min1 && n2 == min2) break;
        n1 = min1, n2 = min2, la = ra, lb = rb;
    }

    for (int i = 1; i <= n; i++) cout << ans[i];
    cout << endl;
}

int main() {
    SYNC;
    int t = 1;
    cin >> t;
    while (t--) oper();
    return 0;
}
/*Avoid Stereotypes, Think More, and Code Less.*/
/*Instead of focusing on troublesome old ideas, it's
better to learn or think about efficient new methods*/