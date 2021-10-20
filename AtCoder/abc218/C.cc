#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<char>> s(n + 2, vector<char>(n + 2, '.'));
    vector<vector<char>> t(n + 2, vector<char>(n + 2, '.'));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> s[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> t[i][j];
        }
    }

    auto is_empty_col = [&n](const vector<vector<char>> &vec, int x) -> bool {
        for (int i = 1; i <= n; ++i) {
            if (vec[i][x] == '#') {
                return false;
            }
        }
        return true;
    };

    auto is_empty_row = [&n](const vector<vector<char>> &vec, int x) -> bool {
        for (int i = 1; i <= n; ++i) {
            if (vec[x][i] == '#') {
                return false;
            }
        }
        return true;
    };

    vector<int> shapeS({0, n+1, 0, n+1}), shapeT({0, n+1, 0, n+1});


    while (shapeS[0] + 1 <= n && is_empty_row(s, shapeS[0] + 1)) {
        ++shapeS[0];
    }
    ++shapeS[0];

    while (shapeS[1] - 1 >= 1 && is_empty_row(s, shapeS[1] - 1)) {
        --shapeS[1];
    }
    --shapeS[1];

    while (shapeS[2] + 1 <= n && is_empty_col(s, shapeS[2] + 1)) {
        ++shapeS[2];
    }
    ++shapeS[2];

    while (shapeS[3] - 1 >= 1 && is_empty_col(s, shapeS[3] - 1)) {
        --shapeS[3];
    }
    --shapeS[3];

    while (shapeT[0] + 1 <= n && is_empty_row(t, shapeT[0] + 1)) {
        ++shapeT[0];
    }
    ++shapeT[0];

    while (shapeT[1] - 1 >= 1 && is_empty_row(t, shapeT[1] - 1)) {
        --shapeT[1];
    }
    --shapeT[1];

    while (shapeT[2] + 1 <= n && is_empty_col(t, shapeT[2] + 1)) {
        ++shapeT[2];
    }
    ++shapeT[2];

    while (shapeT[3] - 1 >= 1 && is_empty_col(t, shapeT[3] - 1)) {
        --shapeT[3];
    }
    --shapeT[3];

    int dhS = shapeS[3] - shapeS[2];
    int dwS = shapeS[1] - shapeS[0];

    int dhT = shapeT[3] - shapeT[2];
    int dwT = shapeT[1] - shapeT[0];

    auto out = [&n](int x) -> bool { return x < 0 || x > n+1; };

    if (dhS == dhT) {
        if (dwS == dwT) {
            bool flag = true;
            for (int i = 0; i < dhS; ++i) {
                for (int j = 0; j < dwS; ++j) {
                    if (out(shapeS[0] + i) || out(shapeS[2] + j) || out(shapeT[0] + i) || out(shapeT[2] + j)) {
                        cout << "No\n";
                        return 0;
                    }
                    if (s[shapeS[0] + i][shapeS[2] + j] != t[shapeT[0] + i][shapeT[2] + j]) {
                        flag = false;
                        break;
                    }
                    if (!flag) {
                        break;
                    }
                }
            }
            if (flag) {
                cout << "Yes\n";
                return 0;
            }
            flag = true;
            for (int i = 0; i < dhS; ++i) {
                for (int j = 0; j < dwS; ++j) {
                    if (out(shapeS[0] + i) || out(shapeS[2] + j) || out(shapeT[1] - i) || out(shapeT[3] - j)) {
                        cout << i << ' ' << j << endl;
                        cout << shapeS[0] + i << ' ' << shapeS[2] + j << endl;
                        cout << shapeT[1] - i << ' ' << shapeT[3] - j << endl;
                        cout << "No\n";
                        return 0;
                    }
                    if (s[shapeS[0] + i][shapeS[2] + j] != t[shapeT[1] - i][shapeT[3] - j]) {
                        flag = false;
                        break;
                    }
                    if (!flag) {
                        break;
                    }
                }
            }
            if (!flag) {
                cout << "No\n";
            } else {
                cout << "Yes\n";
            }
        } else {
            cout << "No\n";
        }
    } else if (dhS == dwT) {
        if (dwS == dhT) {
            bool flag = true;
            for (int i = 0; i < dhS; ++i) {
                for (int j = 0; j < dwS; ++j) {
                    if (out(shapeS[0] + i) || out(shapeS[2] + j) || out(shapeT[1] - j) || out(shapeT[2] - i)) {
                        cout << "No\n";
                        return 0;
                    }
                    if (s[shapeS[0] + i][shapeS[2] + j] != t[shapeT[1] - j][shapeT[2] - i]) {
                        flag = false;
                        break;
                    }
                    if (!flag) {
                        break;
                    }
                }
            }
            if (flag) {
                cout << "Yes\n";
                return 0;
            }
            flag = true;
            for (int i = 0; i < dhS; ++i) {
                for (int j = 0; j < dwS; ++j) {
                    if (out(shapeS[0] + i) || out(shapeS[2] + j) || out(shapeT[1] - j) || out(shapeT[3] - i)) {
                        cout << "No\n";
                        return 0;
                    }
                    if (s[shapeS[0] + i][shapeS[2] + j] != t[shapeT[1] - j][shapeT[3] - i]) {
                        flag = false;
                        break;
                    }
                    if (!flag) {
                        break;
                    }
                }
            }
            if (!flag) {
                cout << "No\n";
            } else {
                cout << "Yes\n";
            }
        } else {
            cout << "No\n";
        }
    } else {
        cout << "No\n";
    }

    return 0;
}