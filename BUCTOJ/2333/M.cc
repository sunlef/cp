#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;

    while (cin >> N >> Q) {
        map<int, deque<int>> q;
        while (Q--) {
            int op;
            cin >> op;
            if (op == 1) {
                int u, w, val;
                cin >> u >> w >> val;
                --u;
                if (w == 0) {
                    q[u].push_front(val);
                } else {
                    q[u].push_back(val);
                }
            } else if (op == 2) {
                int u, w;
                cin >> u >> w;
                --u;
                if (q[u].empty()) {
                    cout << "-1\n";
                } else {
                    if (w == 0) {
                        cout << q[u].front() << '\n';
                        q[u].pop_front();
                    } else {
                        cout << q[u].back() << '\n';
                        q[u].pop_back();
                    }
                }
            } else {
                int u, v, w;
                cin >> u >> v >> w;
                --u, --v;
                if (w == 0) {
                    while (!q[v].empty()) {
                        q[u].push_back(q[v].front());
                        q[v].pop_front();
                    }
                } else {
                    while (!q[v].empty()) {
                        q[u].push_back(q[v].back());
                        q[v].pop_back();
                    }
                }
            }
        }
    }

    return 0;
}