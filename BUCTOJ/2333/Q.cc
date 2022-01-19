#include <deque>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int MAX, N;

    while (cin >> MAX >> N) {
        deque<bool> visited(1e4 + 50);
        for (int i = 0; i < N; ++i) {
            int x;
            cin >> x;

            visited[x] = true;
        }

        int p = 1, cnt = 1;
        char op;
        multiset<int> s;
        while (cin >> op && op != 'e') {
            if (op == 'a') {
                int x;
                cin >> x;
                s.insert(x);
            } else if (op == 'r') {
                if (!s.empty()) {
                    if (p == 1) {
                        if (visited[cnt++]) {
                            cout << *s.begin() << '\n';
                        }
                        s.erase(*s.begin());
                    } else {
                        if (visited[cnt++]) {
                            cout << *s.rbegin() << '\n';
                        }
                        s.erase(*s.rbegin());
                    }
                } else {
                    cout << "-1\n";
                }
            } else if (op == 'p') {
                cin >> p;
            }
        }
        cout << '\n';
    }

    return 0;
}