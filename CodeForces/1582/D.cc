#include <bits/stdc++.h>
using namespace std;

template <typename T_vector> void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++) cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (auto &x : a) {
        cin >> x;
    }

    if (n % 2 == 0) {
        for (int i = 0; i < n; i += 2) {
            cout << -a[i + 1] << ' ' << a[i] << ' ';
        }
        cout << '\n';
    } else {
        srand(2333333);
        int pos1 = 0, pos2 = 1, pos3 = 2;

        do {
            pos1 = rand() % n;
            pos2 = rand() % n;
            pos3 = rand() % n;
        } while (![&]() {
            if (pos1 == pos2 || pos1 == pos3 || pos2 == pos3) {
                return false;
            }
            if (a[pos1] + a[pos2] == 0) {
                return false;
            }
            return true;
        }());

        auto next = [&](int x) -> int {
            int res = x + 1;
            while (res == pos1 || res == pos2 || res == pos3) {
                ++res;
            }
            return res;
        };

        vector<int> ans(n);

        int st = -1;
        st = next(st);

        for (int i = st; i < n;) {
            int posA = i, posB = next(i);
            ans[posA] = -a[posB];
            ans[posB] = a[posA];
            i = next(posB);
        }

        int ans1 = -a[pos3];
        int ans2 = -a[pos3];
        int ans3 = a[pos1] + a[pos2];

        ans[pos1] = ans1;
        ans[pos2] = ans2;
        ans[pos3] = ans3;

        output_vector(ans);
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