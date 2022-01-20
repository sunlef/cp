#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;

    while (cin >> n) {
        vector<vector<int>> position(n, vector<int>(2));
        vector<vector<int>> block(n, vector<int>(n));
        vector<int> top(n);

        for (int i = 0; i < n; i++) {
            position[i][0] = i;
            position[i][1] = 0;
            block[i][0] = i;
            top[i] = 1;
        }

        string action1, action2;

        while (cin >> action1 && action1 != "quit") {
            int a, b;
            cin >> a >> action2 >> b;

            int ax = position[a][0];
            int ay = position[a][1];
            int bx = position[b][0];
            int by = position[b][1];

            if (ax == bx) continue;

            if (action1 == "move") {
                for (int i = ay + 1; i < top[ax]; i++) {
                    position[block[ax][i]][0] = block[ax][i];
                    position[block[ax][i]][1] = top[block[ax][i]];
                    block[block[ax][i]][top[block[ax][i]]++] = block[ax][i];
                }
                top[ax] = ay + 1;
            }

            if (action2 == "onto") {
                for (int i = by + 1; i < top[bx]; i++) {
                    position[block[bx][i]][0] = block[bx][i];
                    position[block[bx][i]][1] = top[block[bx][i]];
                    block[block[bx][i]][top[block[bx][i]]++] = block[bx][i];
                }
                top[bx] = by + 1;
            }

            for (int i = ay; i < top[ax]; i++) {
                position[block[ax][i]][0] = bx;
                position[block[ax][i]][1] = top[bx];
                block[bx][top[bx]++] = block[ax][i];
            }
            top[ax] = ay;
        }

        for (int i = 0; i < n; i++) {
            cout << i << ":";
            for (int j = 0; j < top[i]; j++) {
                cout << ' ' << block[i][j];
            }
            cout << '\n';
        }
    }

    return 0;
}