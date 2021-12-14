#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int64_t n;
    cin >> n;

    int64_t res = 0;
    for (int i = 1; i <= sqrt(n); ++i) {
        res += n / i;
    }
    res *= 2;
    res -= int64_t(sqrt(n)) * int64_t(sqrt(n));

    cout << res << '\n';
    
    return 0;
}