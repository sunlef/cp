#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;

    vector<int> vec(N);
    iota(vec.begin(), vec.end(), 1);

    bool hahaha = false;
    while (vec.size() > 3) {
        vector<int> B;
        if (!hahaha) {
            for (int i = 0; i < int(vec.size()); ++i) {
                if (i % 2 == 0) {
                    B.push_back(vec[i]);
                }
            }
        } else {
            for (int i = 0; i < int(vec.size()); ++i) {
                if (!((i + 1) % 3 == 0)) {
                    B.push_back(vec[i]);
                }
            }
        }

        hahaha = !hahaha;
        vec = B;
    }

    for (int i : vec) {
        cout << i << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        solve();
    }

    return 0;
}