#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> a(n, vector<char>(m));
    vector<vector<int>> visited(n, vector<int>(m, 0));

    for (auto &row : a) {
        for (auto &ch : row) {
            cin >> ch;
        }
    }

    auto check = [&](const pair<int, int> &Node) -> bool {
        int h = Node.first, w = Node.second;
        return h >= 0 && h < n && w >= 0 && w < m && a[h][w] == '*';
    };

    auto L = [](const pair<int, int> &Node) -> pair<int, int> {
        int h = Node.first, w = Node.second;
        return make_pair(h - 1, w - 1);
    };
    auto R = [](const pair<int, int> &Node) -> pair<int, int> {
        int h = Node.first, w = Node.second;
        return make_pair(h - 1, w + 1);
    };

    auto draw = [&](int h, int w) -> void {
        auto tmp = visited;
        tmp[h][w] = 1;
        pair<int, int> A = make_pair(h, w), B = A;
        int size = 0;
        A = L(A);
        B = R(B);
        while (check(A) && check(B)) {
            ++size;
            tmp[A.first][A.second] = tmp[B.first][B.second] = 1;
            A = L(A);
            B = R(B);
        }
        if (size >= k) {
            visited = tmp;
        }
    };

    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '.') {
                visited[i][j] = 1;
            } else {
                draw(i, j);
            }
        }
    }

    for (auto &row : visited) {
        for (auto &x : row) {
            if (!x) {
                cout << "NO" << '\n';
                return;
            }
        }
    }

    cout << "YES\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        solve();
    }

    return 0;
}