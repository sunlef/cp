#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while(cin >> n && n) {
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            ans += x;
        }
        cout << ans << '\n';
    }
    return 0;
}
