#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    while (cin >> n >> m) {
        vector<int> C;
        for (int i = 0; i < n + m; ++i) {
            int x;
            cin >> x;
            C.push_back(x);
        }

        sort(C.begin(), C.end());
        C.erase(unique(C.begin(), C.end()), C.end());
        for (int i : C) {
            cout << i << ' ';
        }
        cout << '\n';
    }

    return 0;
}