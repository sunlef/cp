#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int x, y, fx, fy;
    cin >> x >> y >> fx >> fy;

    int dx = abs(x - fx), dy = abs(y - fy);

    vector<vector<char>> o(4);
    o[0] = {'U', 'D', 'L', 'R'};
    o[1] = {'U', 'D', 'R', 'L'};
    o[2] = {'D', 'U', 'R', 'L'};
    o[3] = {'D', 'U', 'L', 'R'};

    if (x == fx) {
        if (y == fy) {
            cout << '\n';
            return 0;
        } else {
            if (fy > y) {
                for (int i = 0; i < dy; ++i) {
                    cout << 'U';
                }
                cout << 'R';
                for (int i = 0; i < dy; ++i) {
                    cout << 'D';
                }
                cout << 'L' << 'L';
                for (int i = 0; i < dy; ++i) {
                    cout << 'U';
                }
                cout << 'R' << 'U' << 'R' << 'R';
                for (int i = 0; i < dy + 2; ++i) {
                    cout << 'D';
                }
                cout << 'L' << 'L' << 'U' << '\n';
                return 0;
            } else {
                for (int i = 0; i < dy; ++i) {
                    cout << 'D';
                }
                cout << 'R';
                for (int i = 0; i < dy; ++i) {
                    cout << 'U';
                }
                cout << 'L' << 'L';
                for (int i = 0; i < dy; ++i) {
                    cout << 'D';
                }
                cout << 'R' << 'D' << 'R' << 'R';
                for (int i = 0; i < dy + 2; ++i) {
                    cout << 'U';
                }
                cout << 'L' << 'L' << 'D' << '\n';
                return 0;
            }
        }
    } else if (y == fy) {
        if (fx > x) {
            for (int i = 0; i < dx; ++i) {
                cout << 'R';
            }
            cout << 'D';
            for (int i = 0; i < dx; ++i) {
                cout << 'L';
            }
            cout << 'U' << 'U';
            for (int i = 0; i < dx; ++i) {
                cout << 'R';
            }
            cout << 'D' << 'R' << 'D' << 'D';
            for (int i = 0; i < dy + 2; ++i) {
                cout << 'L';
            }
            cout << 'U' << 'U' << 'R' << '\n';
            return 0;
        } else {
            for (int i = 0; i < dx; ++i) {
                cout << 'L';
            }
            cout << 'D';
            for (int i = 0; i < dx; ++i) {
                cout << 'R';
            }
            cout << 'U' << 'U';
            for (int i = 0; i < dx; ++i) {
                cout << 'L';
            }
            cout << 'D' << 'L' << 'D' << 'D';
            for (int i = 0; i < dy + 2; ++i) {
                cout << 'R';
            }
            cout << 'U' << 'U' << 'L' << '\n';
            return 0;
        }
    }

    int t;
    if (fx > x && fy > y) {
        t = 0;
    } else if (fx < x && fy > y) {
        t = 1;
    } else if (fx < x && fy < y) {
        t = 2;
    } else {
        t = 3;
    }

    for (int i = 0; i < dy; ++i) {
        cout << o[t][0];
    }

    for (int i = 0; i < dx; ++i) {
        cout << o[t][3];
    }

    for (int i = 0; i < dy; ++i) {
        cout << o[t][1];
    }

    for (int i = 0; i < dx; ++i) {
        cout << o[t][2];
    }

    cout << o[t][2];

    for (int i = 0; i < dy + 1; ++i) {
        cout << o[t][0];
    }

    for (int i = 0; i < dx + 1; ++i) {
        cout << o[t][3];
    }

    cout << o[t][1];

    cout << o[t][3];

    for (int i = 0; i < dy + 1; ++i) {
        cout << o[t][1];
    }

    for (int i = 0; i < dx + 1; ++i) {
        cout << o[t][2];
    }

    cout << o[t][0];
    cout << '\n';

    return 0;
}