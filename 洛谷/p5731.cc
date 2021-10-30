#include <bits/stdc++.h>
using namespace std;
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define FOR(I, N) for (int I = 0; I < (N); ++I)
#define FORR(I, A, B) for (int I = (A); I < (B); ++I)
#define PB push_back
template <class T> void _R(T &x) { cin >> x; }
void R() {}
template <class T, class... U> void R(T &head, U &...tail) {
    _R(head);
    R(tail...);
}
template <class T> void _W(const T &x) { cout << x; }
void _W(const double &x) { cout << fixed << setprecision(16) << x; }
template <class T, class U> void _W(const pair<T, U> &x) {
    _W(x.first);
    putchar(' ');
    _W(x.second);
}
template <class T> void _W(const vector<T> &x) {
    for (auto i = x.begin(); i != x.end(); _W(*i++))
        if (i != x.cbegin()) putchar(' ');
}
void W() {}
template <class T, class... U> void W(const T &head, const U &...tail) {
    _W(head);
    putchar(sizeof...(tail) ? ' ' : '\n');
    W(tail...);
}
int n;
int g[20][20];
void solve() {
    int k = 1, x = 1, y = 0;
    while (k <= n * n) {
        while (y < n && !g[x][y + 1]) g[x][++y] = k++;
        while (x < n && !g[x + 1][y]) g[++x][y] = k++;
        while (y > 1 && !g[x][y - 1]) g[x][--y] = k++;
        while (x > 1 && !g[x - 1][y]) g[--x][y] = k++;
    }
    FORR(i, 1, n + 1) {
        FORR(j, 1, n + 1) printf("%3d", g[i][j]);
        puts("");
    }
}
void read() { R(n); }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    while (T--) {
        read();
        solve();
    }
    return 0;
}