#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    array<string, 6> s;

    auto calc = [](const string &s1, const string &s2, const string &s3) -> pair<int, int> {
        if (s1.back() == s2.back() && s2.back() == s3.back() && s1.front() + 1 == s2.front() && s2.front() + 1 == s3.front()) {
            return {10, s3.front() - '0'};
        } else if (s1.front() + 1 == s2.front() && s2.front() + 1 == s3.front()) {
            return {9, s3.front() - '0'};
        } else if (s1.front() == s2.front() && s2.front() == s3.front()) {
            return {8, s3.front() - '0'};
        } else if (s1.back() == s2.back() && s2.back() == s3.back()) {
            return {7, s1.front() - '0'};
        } else {
            if (s1.front() == s2.front()) {
                return {6, s1.front() - '0'};
            } else if (s2.front() == s3.front()) {
                return {6, s2.front() - '0'};
            } else {
                return {4, max({s1.front(), s2.front(), s3.front()}) - '0'};
            }
        }
    };

    while (cin >> s[0] >> s[1] >> s[2] >> s[3] >> s[4] >> s[5]) {
        sort(s.begin(), s.begin() + 3);
        sort(s.begin() + 3, s.end());

        auto A = calc(s[0], s[1], s[2]);
        auto B = calc(s[3], s[4], s[5]);

        if (A > B) {
            cout << "zhangsan\n";
        } else if (A < B) {
            cout << "lisi\n";
        } else {
            cout << "tie\n";
        }
    }

    return 0;
}