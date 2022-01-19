#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int &i : A) {
        cin >> i;
    }

    sort(A.begin(), A.end(), greater<int>());
    cout << A[K - 1] << '\n';

    return 0;
}