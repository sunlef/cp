#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> id(N);
    for (int &i : id) {
        cin >> i;
    }

    auto A = id;
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());

    vector<int> idx(A.size());
    for (int &i : id) {
        int pos = lower_bound(A.begin(), A.end(), i) - A.begin();
        idx[pos] = i;
        i = pos;
    }

    vector<vector<int>> position(A.size());
    for (int i = 0; i < N; ++i) {
        position[id[i]].push_back(i);
    }

    for (int i = int(A.size()) - 1; i >= 0; --i) {
        bool found = false;
        for (int j = 1; j < int(position[i].size()); ++j) {
            if (position[i][j] - position[i][j - 1] <= K) {
                found = true;
                break;
            }
        }
        if (found) {
            cout << idx[i] << '\n';
            return 0;
        }
    }

    cout << "-1\n";
    return 0;
}