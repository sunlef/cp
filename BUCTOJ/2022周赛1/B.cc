#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int k, s;
    cin >> k >> s;

    int ans = 0;
    for (int i = 0; i <= k; ++i) {
        for (int j = 0; j <= k; ++j) {
            int _k = s - i - j;
            if (_k >= 0 && _k <= k) {
                ++ans;
            }
        }
    }
    cout << ans << '\n';
    
    return 0;
}