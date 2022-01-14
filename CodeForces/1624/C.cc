#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int &i : A) {
        cin >> i;
    }

    deque<bool> visited(N + 1);
    for (int &i : A) {
        while (i > N || (visited[i] && i > 0)) {
            i /= 2;
        }
        visited[i] = true;
    }

    cout << (reduce(visited.begin() + 1, visited.end(), int()) == N ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        solve();
    }

    return 0;
}