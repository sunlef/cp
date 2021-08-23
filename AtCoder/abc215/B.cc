#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < 60; ++i) {
        if(1ll << i > n) {
            cout << ans << '\n';
            return 0;
        } else {
            ans = i;
        }
    }
    
    cout << ans << '\n';

    return 0;
}