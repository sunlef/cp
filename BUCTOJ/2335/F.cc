#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, ign;
    int c, p;

    map<string, int> price;
    map<string, int> cnt;

    while (cin >> s >> c >> p >> ign) {
        price[s] += c * p;
        cnt[s] += c;
    }

    vector<tuple<int, string, int>> vec;

    for (auto &[str, pr] : price) {
        vec.push_back({cnt[str], str, pr});
    }

    sort(vec.begin(), vec.end(), [](const tuple<int, string, int> &lhs, const tuple<int, string, int> &rhs) {
        if (get<0>(lhs) == get<0>(rhs)) {
            return get<1>(lhs) < get<1>(rhs);
        } else {
            return lhs > rhs;
        }
    });

    for (auto &[cnt, str, pr] : vec) {
        cout << str << ' ' << cnt << ' ' << pr << '\n';
    }

    return 0;
}