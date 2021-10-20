#include <bits/stdc++.h>
using namespace std;

bool check(int x) {
    if (x < 2)
        return false;
    for (int i = 2; i <= sqrt(x); ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for(int i = 2; i <= n; ++i) {
        for(int j = 2; i + j <= n; ++j) {
            int k = n - i - j;
            if(check(i) && check(j) && check(k)) {
                cout << i << ' ' << j << ' ' << k << '\n';
                return 0;
            }
        }
    }

    return 0;
}
