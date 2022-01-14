#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    auto query = [](int A, int B, int C) -> int {
        cout << "? " << A + 1 << ' ' << B + 1 << ' ' << C + 1 << endl;
        int x;
        cin >> x;
        return x;
    };

    int C = -1, I = -1;
    int last = -1;
    int lastp = -1;

    for (int i = 0; i < n; i++) {
        int now = query(i, (i + 1) % n, (i + 2) % n);
        int nowp = (i + 2) % n;

        if (last != -1 && now != last) {
            if (last == 1) {
                C = lastp, I = nowp;
            } else {
                C = nowp, I = lastp;
            }
        }

        last = now;
        lastp = i;
    }

    vector<int> ans;
    ans.push_back(I + 1);
    for (int i = 0; i < n; ++i) {
        if (i == C || i == I) {
            continue;
        }

        if (!query(i, C, I)) {
            ans.push_back(i + 1);
        }
    }

    cout << "! " << ans.size() << ' ';
    for (auto ANS : ans) {
        cout << ANS << ' ';
    }
    cout << endl;
}

int main() {
    int T;
    std::cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        solve();
    }

    return 0;
}