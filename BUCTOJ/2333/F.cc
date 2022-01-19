#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    vector<int> cnt(26);

    while (cin >> S) {
        for (int i = 0; i < int(S.size()); ++i) {
            if (S[i] >= 'a' && S[i] <= 'z') {
                ++cnt[S[i] - 'a'];
            } else if (S[i] == '#') {
                for (int i = 0; i < 26; ++i) {
                    cout << char(i + 'a') << ' ' << cnt[i] << '\n';
                }
                return 0;
            }
        }
    }

    return 0;
}