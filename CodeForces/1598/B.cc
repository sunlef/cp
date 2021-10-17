#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(5, 0));

    for (auto &people : a) {
        for (auto &day : people) {
            cin >> day;
        }
    }

    int num = n / 2;

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (i == j) {
                continue;
            }
            int A = 0, B = 0, C = 0;
            for (auto &people : a) {
                if (people[i] && !people[j]) {
                    ++A;
                } else if (people[i] && people[j]) {
                    ++B;
                } else if (!people[i] && people[j]) {
                    ++C;
                }
            }
            if (A > num) {
                continue;
            }
            int L = num - A;
            B -= L;
            if (B < 0) {
                continue;
            }
            C += B;
            if (C == num) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
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