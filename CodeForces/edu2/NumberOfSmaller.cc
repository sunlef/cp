#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (auto &x : a) {
        cin >> x;
    }
    for (auto &x : b) {
        cin >> x;
    }
    
    a.push_back(INT_MAX);
    int i = 0;

    for (int j = 0; j < m; ++j) {
        while (a[i] < b[j]) {
            ++i;
        }
        cout << i << ' ';
    }
    cout << '\n';
    
    return 0;
}