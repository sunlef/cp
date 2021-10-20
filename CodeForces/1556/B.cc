#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    bool a[n], b[n];

    vector<int> odd, even;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x & 1) {
            a[i] = b[i] = true;
            odd.emplace_back(i);
        } else {
            a[i] = b[i] = false;
            even.emplace_back(i);
        }
    }

    if (n == 1) {
        cout << 0 << '\n';
        return;
    }

    if (n & 1) {
        if (!bool(abs(int(even.size()) - int(odd.size())) == 1)) {
            cout << -1 << '\n';
            return;
        }
    } else {
        if (int(even.size()) != int(odd.size())) {
            cout << -1 << '\n';
            return;
        }
    }

    int ans = INT_MAX;
    int ans1 = 0, ans2 = 0;
    
    int posodd = 0, poseven = 0;
    if (int(odd.size()) == int(even.size()) || int(even.size() - odd.size()) == 1) {
        for (int i = 0; i < n; ++i) {
            if (i & 1) {
                if (a[i]) {
                    ++posodd;
                } else {
                    ans1 += odd[posodd] - i;
                    a[odd[posodd]] = false;
                    ++posodd;
                }

            } else {
                if (!a[i]) {
                    ++poseven;
                } else {
                    ans1 += even[poseven] - i;
                    a[even[poseven]] = true;
                    ++poseven;
                }
            }
        }
        ans = min(ans, ans1);
    }

    if (int(odd.size()) == int(even.size()) || int(odd.size() - even.size()) == 1) {
        posodd = poseven = 0;
        for (int i = 0; i < n; ++i) {
            if (i & 1) {
                if (!b[i]) {
                    ++poseven;
                } else {
                    ans2 += even[poseven] - i;
                    b[even[poseven]] = true;
                    ++poseven;
                }
            } else {
                if (b[i]) {
                    ++posodd;
                } else {
                    ans2 += odd[posodd] - i;
                    b[odd[posodd]] = false;
                    ++posodd;
                }
            }
        }
        ans = min(ans, ans2);
    }
    cout << ans << '\n';
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