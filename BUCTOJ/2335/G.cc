#include <bits/stdc++.h>
using namespace std;

int h[100], nxt[1000], to[1000], CNT = 0;
void add(int u, int v) {
    to[CNT] = v;
    nxt[CNT] = h[u];
    h[u] = CNT++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;

    while (cin >> N >> M && !(N == 0 && M == 0)) {
        memset(h, -1, sizeof h);
        memset(nxt, -1, sizeof nxt);
        CNT = 0;

        for (int i = 0; i < M; ++i) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            add(u, v);
        }

        vector<int> color(N);

        bool cycle = false;
        function<void(int, int)> f = [&](int u, int c) -> void {
            if (color[u] == c) {
                cycle = true;
                return;
            }
            color[u] = c;
            for (int e = h[u]; e != -1; e = nxt[e]) {
                int v = to[e];
                f(v, c);
            }
        };

        int cnt = 0;
        for (int i = 0; i < N; ++i) {
            if (!color[i]) {
                f(i, ++cnt);
            }
        }

        cout << (cycle ? "YES\n" : "NO\n");
    }


    return 0;
}