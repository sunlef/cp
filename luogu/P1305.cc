#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> sons(27, {-1, -1});
    deque<bool> used(27, 0);
    vector<int> in(27, 0);

    for (int i = 0; i < n; ++i) {
        char a, b, c;
        cin >> a >> b >> c;

        int u = a - 'a' + 1;
        int l = b - 'a' + 1;
        int r = c - 'a' + 1;

        used[u] = true;

        if (b != '*') {
            used[l] = true;
            sons[u].first = l;
            in[l]++;
        }
        if (c != '*') {
            used[r] = true;
            sons[u].second = r;
            in[r]++;
        }
    }

    int root = -1;
    for (int i = 1; i <= 26; ++i) {
        if (used[i] && in[i] == 0) {
            root = i;
        }
    }
    assert(root != -1);

    function<void(int)> dfs = [&](int u) -> void {
        cout << char(u + 'a' - 1);
        if (sons[u].first != -1) {
            dfs(sons[u].first);
        }
        if (sons[u].second != -1) {
            dfs(sons[u].second);
        }
    };

    dfs(root);

    cout << '\n';
    return 0;
}