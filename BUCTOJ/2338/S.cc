#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define MOD
using namespace std;
#define LL long long
#define N 255
int n, b, q, a, f1[N][N][15], f2[N][N][15];

void ST_prework() {
    int t = log(n) / log(2);
    for (int k = 1; k <= n; k++) {
        for (int j = 1; j <= t; j++) {
            for (int i = 1; i <= n + 1 - (1 << j); i++) {
                f1[k][i][j] = max(f1[k][i][j - 1], f1[k][i + (1 << (j - 1))][j - 1]);
                f2[k][i][j] = min(f2[k][i][j - 1], f2[k][i + (1 << (j - 1))][j - 1]);
            }
        }
    }
}

int ST_query(int l, int r) {
    int k = log(b) / log(2);
    int ma = 0, mi = 0x3f3f3f3f;  //不能忘
    for (int i = l; i < l + b; i++) {
        ma = max(max(f1[i][r][k], f1[i][(r + b - 1) - (1 << k) + 1][k]), ma);
        mi = min(min(f2[i][r][k], f2[i][(r + b - 1) - (1 << k) + 1][k]), mi);
    }
    return ma - mi;
}

int main() {
    while (scanf("%d%d%d", &n, &b, &q) != EOF) {
        memset(f1, 0, sizeof f1);
        memset(f2, 0, sizeof f2);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int t;
                scanf("%d", &t);
                f1[i][j][0] = t, f2[i][j][0] = t;
            }
        }

        ST_prework();
        for (int i = 1; i <= q; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            cout << ST_query(x, y) << '\n';
        }
    }
}
