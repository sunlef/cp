#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d ", &n);

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        getline(cin, s);
        for (auto &ch : s) {
            ans += ch == '-';
        }
    }
    cout << ans << '\n';

    return 0;
}