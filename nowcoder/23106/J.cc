#include <bits/stdc++.h>
using namespace std;

void solve() {
    int A, B, N;
    cin >> A >> B >> N;

    vector<int> a(A), b(B);
    for (int &i : a) {
        cin >> i;
    }
    for (int &i : b) {
        cin >> i;
    }

    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());

    for (int i = 1; i < A; ++i) {
        a[i] += a[i - 1];
    }
    for (int i = 1; i < B; ++i) {
        b[i] += b[i - 1];
    }

    int ans = -1;

    for (int aa = 0; aa <= N; ++aa) {
        int bb = N - aa;
        if (aa > A || bb < 0 || bb > N / 2 || bb > B) {
            continue;
        }
        ans = max(ans, a[aa - 1] + b[bb - 1]);
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