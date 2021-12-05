#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cnt = 0;
    for (int i = 1; i <= 2021; ++i) {
        if (__gcd(2021, i) > 1) {
            cout << i << '\n';
            ++cnt;
        }
    }
    cout << cnt << '\n';

    return 0;
}