#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N;
    cin >> M >> N;

    string A, B;
    cin >> A >> B;

    int cnt = 0;
    for (int i = 0; i < min(M, N); ++i) {
        if (A[i] != B[i]) {
            ++cnt;
        }
    }

    cout << cnt + abs(M - N) << '\n';

    return 0;
}