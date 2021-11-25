#include <bits/stdc++.h>
using namespace std;
constexpr int highbit(int x) { return 31 - __builtin_clz(x); }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i <= __lg(n); ++i) {
            for (int j = 0; j <= n - (1 << i); ++j) {
                cout << j << ' ' << i << endl;
            }
        }

    return 0;
}