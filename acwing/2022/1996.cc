#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<string> str(N), A(N), B(N);

    for (int i = 0; i < N; ++i) {
        cin >> str[i];
        A[i] = B[i] = str[i];

        sort(A[i].begin(), A[i].end());
        sort(B[i].begin(), B[i].end(), greater<char>());
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for (string &i : str) {
        sort(i.begin(), i.end());
        cout << lower_bound(B.begin(), B.end(), i) - B.begin() + 1 << ' ';
        sort(i.begin(), i.end(), greater<char>());
        cout << upper_bound(A.begin(), A.end(), i) - A.begin() << '\n';
    }

    return 0;
}