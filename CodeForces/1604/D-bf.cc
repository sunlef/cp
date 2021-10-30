#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int64_t x, y;
    cin >> x >> y;
    for (int64_t i = 1; i <= 10000000000; ++i) {
        if (i % x == y % i) {
            cout << i << '\n';
        }
    }
    
    return 0;
}