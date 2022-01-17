#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto fmt_to_minutes = [](const string& str) -> int {
        return (str[4] - '0') + 10 * (str[3] - '0') + 60 * ((str[1] - '0') + 10 * (str[0] - '0') - 18);
    };

    auto minutes_to_fmt = [](int x) -> string {
        int H = x / 60;
        int M = x % 60;
        string A, B;
        if (H < 10) {
            A = '0' + to_string(H);
        } else {
            A = to_string(H);
        }

        if (M < 10) {
            B = '0' + to_string(M);
        } else {
            B = to_string(M);
        }

        return A + ':' + B;
    };

    int N;
    while (cin >> N) {
        vector<int> problems(26);
        deque<bool> ok(26);
        for (int i = 0; i < N; ++i) {
            string t, st;
            char p;
            cin >> t >> p >> st;
            if (ok[p - 'A']) {
                continue;
            }
            if (st != "AC") {
                problems[p - 'A'] += 20;
            } else {
                ok[p - 'A'] = true;
                problems[p - 'A'] += fmt_to_minutes(t);
            }
        }

        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            if (ok[i]) {
                ans += problems[i];
            }
        }

        cout << minutes_to_fmt(ans) << '\n';
    }

    return 0;
}