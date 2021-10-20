#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    vector<int> ans;

    int N = a + b;
    if (N & 1) {
        int A = (a + b - 1) / 2, B = (a + b + 1) / 2;
        for (int i = 0; i <= a; ++i) {
            int t1 = i, t2 = a - i;
            if (t1 > A) {
                t1 = A;
                t2 = a - A;
            }
            if (t2 > B) {
                t2 = B;
                t1 = a - B;
            }
            ans.emplace_back(t2 + b - (B - t2));
        }
        A = (a + b + 1) / 2, B = (a + b - 1) / 2;
        for (int i = 0; i <= a; ++i) {
            int t1 = i, t2 = a - i;
            if (t1 > A) {
                t1 = A;
                t2 = a - A;
            }
            if (t2 > B) {
                t2 = B;
                t1 = a - B;
            }
            ans.emplace_back(t2 + b - (B - t2));
        }
    } else {
        int L = N / 2;
        for (int i = 0; i <= a; ++i) {
            int t1 = i, t2 = a - i;
            if (t1 > L) {
                t1 = L;
                t2 = a - L;
            }
            if (t2 > L) {
                t2 = L;
                t1 = a - L;
            }
            ans.emplace_back(t2 + b - (L - t2));
        }
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout << ans.size() << '\n';
    for (auto &x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
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