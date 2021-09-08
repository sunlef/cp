#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    s = '#' + s;

    vector<vector<char>> outcome(n + 1, vector<char>(n + 1, '?'));
    for (int i = 1; i <= n; ++i) {
        outcome[i][i] = 'X';
        if (s[i] == '1') {
            for (int j = 1; j <= n; ++j) {
                if (i == j) {
                    continue;
                }
                outcome[i][j] = outcome[j][i] = '=';
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (s[i] == '1') {
            continue;
        }

        for (int j = 1; j <= n; ++j) {
            if (i == j) {
                continue;
            }
            if (outcome[i][j] == '?') {
                outcome[i][j] = '+';
                outcome[j][i] = '-';
                break;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (outcome[i][j] == '?') {
                if (outcome[j][i] != '?') {
                    cout << "NO" << '\n';
                    return;
                } else {
                    outcome[i][j] = outcome[j][i] = '=';
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        bool flag = false;
        if (s[i] == '2') {
            for (int j = 1; j <= n; ++j) {
                if (i == j) {
                    continue;
                }
                if (outcome[i][j] == '+') {
                    flag = true;
                    break;
                }
            }
        } else {
            flag = true;
            for (int j = 1; j <= n; ++j) {
                if (i == j) {
                    continue;
                }
                if (outcome[i][j] == '-') {
                    flag = false;
                    break;
                }
            }
        }

        if (!flag) {
            cout << "NO" << '\n';
            return;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (outcome[i][j] == 'X') {
                continue;
            } else if (outcome[i][j] == '=') {
                if (outcome[j][i] != '=') {
                    cout << "NO" << '\n';
                    return;
                }
            } else if (outcome[i][j] == '+') {
                if (outcome[j][i] != '-') {
                    cout << "NO" << '\n';
                    return;
                }
            } else {
                if (outcome[j][i] != '+')  {
                    cout << "NO" << '\n';
                    return;
                }
            }
        }
    }

    cout << "YES" << '\n';
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << outcome[i][j];
        }
        cout << '\n';
    }
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