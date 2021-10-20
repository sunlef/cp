#include <bits/stdc++.h>
using namespace std;


bool bf_is_prime(long long x) {
    if (x < 2) return false;
    long long rt = sqrt(x);
    for (int i = 2; i <= rt; ++i)
        if (x % i == 0) return false;
    return true;
}


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);

    int sum = 0;
    for (auto &x : a) {
        cin >> x;
        sum += x;
    }


    if (!bf_is_prime(sum)) {
        cout << n << '\n';
        for (int i = 1; i <= n; ++i) {
            cout << i << ' ';
        }
        cout << '\n';
    } else {
        cout << n - 1 << '\n';
        for (int i = 0; i < n; ++i) {
            if (!bf_is_prime(sum - a[i])) {
                for (int j = 0; j < n; ++j) {
                    if (i != j) {
                        cout << j + 1 << ' ';
                    }
                }
                cout << '\n';
                return;
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        solve();
    }

    return 0;
}