#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    array<string, 10> a;

    map<char, int> mp;

    for (int i = '2'; i <= '9'; ++i) {
        mp[i] = i - '2';
    }

    mp['T'] = 8;
    mp['J'] = 9;
    mp['Q'] = 10;
    mp['K'] = 11;
    mp['A'] = 12;

    using pic = pair<int, char>;
    auto calc = [](const pic &s1, const pic &s2, const pic &s3, const pic &s4, const pic &s5) -> pair<int, tuple<int, int, int, int, int>> {
        if (s1.first + 1 == s2.first && s2.first + 1 == s3.first && s3.first + 1 == s4.first && s4.first + 1 == s5.first &&
            s1.second == s2.second && s2.second == s3.second && s3.second == s4.second && s4.second == s5.second) {
            return {9, {s5.first, s5.first, s5.first, s5.first, s5.first}};
        } else if (s1.first == s2.first && s2.first == s3.first && s3.first == s4.first) {
            return {8, {s1.first, s1.first, s1.first, s1.first, s1.first}};
        } else if (s2.first == s3.first && s3.first == s4.first && s4.first == s5.first) {
            return {8, {s2.first, s2.first, s2.first, s2.first, s2.first}};
        } else if (s1.first == s2.first && s2.first == s3.first && s3.first != s4.first && s4.first == s5.first) {
            return {7, {s1.first, s1.first, s1.first, s1.first, s1.first}};
        } else if (s1.first == s2.first && s2.first != s3.first && s3.first == s4.first && s4.first == s5.first) {
            return {7, {s3.first, s3.first, s3.first, s3.first, s3.first}};
        } else if (s1.second == s2.second && s2.second == s3.second && s3.second == s4.second && s4.second == s5.second) {
            return {6, {s5.first, s4.first, s3.first, s2.first, s1.first}};
        } else if (s1.first + 1 == s2.first && s2.first + 1 == s3.first && s3.first + 1 == s4.first && s4.first + 1 == s5.first) {
            return {5, {s5.first, s5.first, s5.first, s5.first, s5.first}};
        } else if (s1.first == s2.first && s2.first == s3.first && s3.first != s4.first && s4.first != s5.first && s3.first != s5.first) {
            return {4, {s1.first, s1.first, s1.first, s1.first, s1.first}};
        } else if (s1.first != s2.first && s2.first != s3.first && s1.first != s3.first && s3.first == s4.first && s4.first == s5.first) {
            return {4, {s3.first, s3.first, s3.first, s3.first, s3.first}};
        } else if (s1.first == s2.first && s2.first != s3.first && s3.first == s4.first && s4.first != s5.first) {
            return {3, {s3.first, s2.first, s5.first, s5.first, s5.first}};
        } else if (s1.first == s2.first && s2.first != s3.first && s3.first != s4.first && s4.first == s5.first) {
            return {3, {s5.first, s1.first, s3.first, s3.first, s3.first}};
        } else if (s1.first != s2.first && s2.first == s3.first && s3.first != s4.first && s4.first == s5.first) {
            return {3, {s5.first, s3.first, s1.first, s1.first, s1.first}};
        } else if (s1.first == s2.first && s2.first != s3.first && s3.first != s4.first && s4.first != s5.first) {
            return {2, {s1.first, s5.first, s4.first, s3.first, s3.first}};
        } else if (s2.first == s3.first && s1.first != s2.first && s3.first != s4.first && s4.first != s5.first) {
            return {2, {s2.first, s5.first, s4.first, s1.first, s1.first}};
        } else if (s3.first == s4.first && s1.first != s2.first && s2.first != s3.first && s3.first != s5.first) {
            return {2, {s3.first, s5.first, s2.first, s1.first, s1.first}};
        } else if (s4.first == s5.first && s1.first != s2.first && s2.first != s3.first && s3.first != s4.first) {
            return {2, {s5.first, s3.first, s2.first, s1.first, s1.first}};
        } else {
            return {1, {s5.first, s4.first, s3.first, s2.first, s1.first}};
        }
    };


    while (cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5] >> a[6] >> a[7] >> a[8] >> a[9]) {
        array<pair<int, char>, 10> s;
        for (int i = 0; i < 10; ++i) {
            s[i].first = mp[a[i].front()];
            s[i].second = a[i].back();
        }

        // for (auto [A, B] : s) {
        //     cout << A << ' ' << B << '\n';
        // }

        sort(s.begin(), s.begin() + 5);
        sort(s.begin() + 5, s.end());

        auto A = calc(s[0], s[1], s[2], s[3], s[4]);
        auto B = calc(s[5], s[6], s[7], s[8], s[9]);

        // cout << A.first << ' ';
        // auto [q, w, e, r, t] = A.second;
        // cout << q << ' ' << w << ' ' << e << ' ' << r << ' ' << t << '\n';

        // cout << B.first << ' ';
        // auto [q1, w1, e1, r1, t1] = B.second;
        // cout << q1 << ' ' << w1 << ' ' << e1 << ' ' << r1 << ' ' << t1 << '\n';

        if (A < B) {
            cout << "White wins.\n";
        } else if (A > B) {
            cout << "Black wins.\n";
        } else {
            cout << "Tie.\n";
        }
    }

    return 0;
}