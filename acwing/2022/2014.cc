#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    if (N == 1) {
        cout << "1\n";
        return 0;
    }

    vector<int> H(N);
    for (int &i : H) {
        cin >> i;
    }

    vector<int> A;
    A.push_back(H.front());
    for (int i = 1; i < N; ++i) {
        if (H[i] != H[i - 1]) {
            A.push_back(H[i]);
        }
    }

    vector<pair<int, int>> B(A.size());
    for (int i = 0; i < int(A.size()); ++i) {
        B[i] = {A[i], i};
    }
    sort(B.begin(), B.end());

    int ans = 1, now = 1;
    for (int i = 0; i < int(B.size()); ++i) {
        auto &[height, idx] = B[i];

        if (idx == 0) {
            if (A[idx + 1] < A[idx]) {
                --now;
            }
        } else if (idx == int(A.size()) - 1) {
            if (A[idx] > A[idx - 1]) {
                --now;
            }
        } else {
            if (A[idx] < A[idx - 1] && A[idx] < A[idx + 1]) {
                ++now;
            } else if (A[idx] > A[idx - 1] && A[idx] > A[idx + 1]) {
                --now;
            }
        }

        if (i == int(B.size()) - 1 || B[i].first != B[i + 1].first) {
            ans = max(ans, now);
        }
    }

    cout << ans << '\n';
    return 0;
}