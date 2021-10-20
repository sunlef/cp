#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> cnt(10, 0);

    for(int i = n; i <= m; ++i) {
        int x = i;
        while(x) {
            ++cnt[x%10];
            x /= 10;
        }
    }

    for(auto &x : cnt) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}
