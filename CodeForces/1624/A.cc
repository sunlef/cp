#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int &i : A) {
        cin >> i;
    }

    int ans = 0;
    int MAX = *ranges::max_element(A);
    for (int i : A) {
        ans = max(ans, MAX - i);
    }

    cout << ans << '\n';
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