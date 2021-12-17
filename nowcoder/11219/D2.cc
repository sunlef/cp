#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans = {{0, 8, 8, 8, 8, 8, 8}, {1, 0, 8, 8, 8, 8, 8}, {1, 1, 0, 7, 4, 1, 8}, {2, 1, 3, 0, 2, 4, 8},
                           {2, 1, 1, 3, 0, 2, 6}, {2, 1, 1, 6, 3, 0, 8}, {2, 1, 1, 7, 5, 2, 0}};

void solve() {
    int x, y;
    cin >> x >> y;
    cout << (ans[x - 1][y - 1] == 8 ? -1 : ans[x - 1][y - 1]) << '\n';;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    std::cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        solve();
    }

    return 0;
}