#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> d(n);

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        ++d[u], ++d[v];
    }

    int C = n - 1;
    int U = 1;
    int cc = 0, uu = 0;
    for (int i = 0; i < n; ++i) {
        if (d[i] == C) {
            ++cc;
        } else if(d[i] == U) {
            ++uu;
        }
    }

    if (cc == 1 && uu == n - 1) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}