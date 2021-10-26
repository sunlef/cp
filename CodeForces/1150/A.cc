#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, r;
    cin >> n >> m >> r;
    vector<int> a(n), b(m);
    for (auto &x : a) {
        cin >> x;
    }
    for (auto &x : b) {
        cin >> x;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());
    if (b[0] < a[0]) {
        cout << r << '\n';
        return 0;
    }
    int c = r / a[0];
    r -= c * a[0];
    r += c * b[0];
    cout << r << '\n';

    return 0;
}