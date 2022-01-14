#include <bits/stdc++.h>
using namespace std;

constexpr int SIZE = 2010;

int pos, n, m, k;

int64_t asterisk[SIZE];
int64_t nums[SIZE];

int64_t x;

string s, s2;

void solve() {
    m = 0, pos = 0;
    fill(asterisk, asterisk + SIZE, 0);
    fill(nums, nums + SIZE, 0);

    cin >> n >> k >> x;
    --x;

    cin >> s;

    s = '?' + s;

    for (int i = 1; i <= n; ++i) {
        if (s[i] == '*') {
            if (s[i - 1] != '*') {
                asterisk[++m] = k;
            } else {
                asterisk[m] += k;
            }
        }
    }

    reverse(asterisk + 1, asterisk + m + 1);
    for (int i = 1; i <= m; ++i) {
        nums[i] = x % (asterisk[i] + 1);
        x /= asterisk[i] + 1;
    }

    reverse(nums + 1, nums + m + 1);
    for (int i = 1; i <= n; ++i) {
        if (s[i] == '*' && s[i - 1] != '*' && pos < m) {
            s2 = string(nums[++pos], 'b');
            cout << s2;
        } else if (s[i] != '*') {
            cout << s[i];
        }
    }

    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    std::cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        solve();
    }

    return 0;
}