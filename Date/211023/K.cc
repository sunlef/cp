#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, n;
    cin >> a >> b >> n;

    vector<int> l(a + 1);
    for (int i = 1; i <= a; ++i) {
        cin >> l[i];
    }

    int ansa, ansb;
    int nowa = a, cur = b;

    while (n--) {
        cur = nowa;
        nowa = 1;

        while (nowa <= a && cur - l[nowa] >= 1) {
            cur -= l[nowa++];
        }

        ansa = nowa;
        ansb = cur;

        if (nowa == 1 && cur == 1) {
            break;
        } else if (nowa == a && cur == b) {
            break;
        }
    }

    cout << ansa << '-' << ansb << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        cout << "Case #" << TwT << ": ";
        solve();
    }

    return 0;
}