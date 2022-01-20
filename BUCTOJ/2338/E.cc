#include <bits/stdc++.h>
using namespace std;

vector<int> sub(vector<int> &A, vector<int> &B) {
    vector<int> C;
    for (int i = 0, t = 0; i < int(A.size()); i++) {
        t = A[i] - t;
        if (i < int(B.size())) t -= B[i];
        C.push_back((t + 10) % 10);
        if (t < 0)
            t = 1;
        else
            t = 0;
    }

    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    while (cin >> a >> b) {
        vector<int> A(a.size()), B(b.size());
        for (int i = 0; i < int(a.size()); ++i) {
            A[i] = a[i] - '0';
        }
        for (int i = 0; i < int(b.size()); ++i) {
            B[i] = b[i] - '0';
        }

        reverse(A.begin(), A.end());
        reverse(B.begin(), B.end());

        auto C = sub(A, B);

        reverse(C.begin(), C.end());
        for (int i : C) {
            cout << i;
        }
        cout << '\n';
    }

    return 0;
}