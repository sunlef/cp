#include <bits/stdc++.h>
using namespace std;

template <typename T, typename T_iterable> vector<pair<T, int>> run_length_encoding(const T_iterable &items) {
    vector<pair<T, int>> encoding;
    T previous;
    int count = 0;

    for (const T &item : items)
        if (item == previous) {
            count++;
        } else {
            if (count > 0) encoding.emplace_back(previous, count);

            previous = item;
            count = 1;
        }

    if (count > 0) encoding.emplace_back(previous, count);

    return encoding;
}

void solve() {
    int64_t n, k, x;
    cin >> n >> k >> x;
    --x;

    string s;
    cin >> s;

    auto encoded = run_length_encoding<char>(s);

    ranges::reverse(encoded);

    for (auto &[ch, cnt] : encoded) {
        if (ch == '*') {
            int CUTOFF = cnt * k + 1;
            cnt = x % CUTOFF;
            x /= CUTOFF;
            ch = 'b';
        }
    }

    ranges::reverse(encoded);

    for (auto [ch, cnt] : encoded) {
        string ans(cnt, ch);
        cout << ans;
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