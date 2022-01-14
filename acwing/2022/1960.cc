#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    i64 B;
    cin >> N >> B;

    string S(N, '?');
    for (char &ch : S) {
        cin >> ch;
    }

    auto nxt = [&](string str) -> string {
        string res = str;
        for (int i = 0; i < N; ++i) {
            char lst = i == 0 ? str.back() : str[i - 1];
            res[i] = ((str[i] - '0') ^ (lst - '0')) + '0';
        }
        return res;
    };

    map<string, int> mp;
    map<int, string> rmp;

    int now = 0;
    while (!mp.count(S)) {
        if (now == B) {
            for (auto ch : S) {
                cout << ch << '\n';
            }
            return 0;
        }
        mp[S] = now;
        rmp[now] = S;
        ++now;
        S = nxt(S);
    }

    int ST = mp[S];
    int len = now - ST;

    int found = (B - ST) % len + ST;

    for (auto ch : rmp[found]) {
        cout << ch << '\n';
    }
    return 0;
}