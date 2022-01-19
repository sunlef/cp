#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int>> s(N);

    for (auto &vec : s) {
        int c;
        cin >> c;
        while (c--) {
            int x;
            cin >> x;
            vec.push_back(x);
        }
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int u, v;
        cin >> u >> v;
        if ([&]() -> bool {
                for (auto &vec : s) {
                    int p1 = lower_bound(vec.begin(), vec.end(), u) - vec.begin();
                    int p2 = lower_bound(vec.begin(), vec.end(), v) - vec.begin();

                    if (p1 < int(vec.size()) && p2 < int(vec.size()) && vec[p1] == u && vec[p2] == v) {
                        return true;
                    }
                }
                return false;
            }()) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}