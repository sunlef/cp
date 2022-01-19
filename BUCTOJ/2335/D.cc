#include <bits/stdc++.h>
using namespace std;

bool ok;
void f(int now, int step, int A, int B, int C, int D) {
    if (step == 3) {
        ok |= now == 24;
        return;
    } else {
        int a, b;
        if (step == 0) {
            a = A, b = B;
        } else if (step == 1) {
            a = now, b = C;
        } else {
            a = now, b = D;
        }
        f(a + b, step + 1, A, B, C, D);
        f(a - b, step + 1, A, B, C, D);
        f(b - a, step + 1, A, B, C, D);
        if (b && a % b == 0) {
            f(a / b, step + 1, A, B, C, D);
        }
        if (a && b % a == 0) {
            f(b / a, step + 1, A, B, C, D);
        }
        f(a * b, step + 1, A, B, C, D);
    }
}

bool solve(int A, int B, int C, int D) {
    ok = false;
    vector<int> a = {A, B, C, D};
    for (int i = 0; i < 24; ++i) {
        f(0, 0, a[0], a[1], a[2], a[3]);
        next_permutation(a.begin(), a.end());
    }
    return ok;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B, C, D;
    while (cin >> A >> B >> C >> D && A) {
        if (solve(A, B, C, D)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}