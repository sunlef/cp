#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B;
    cin >> A >> B;

    int a = 0, b = 0;
    for (int i = 1; i < A; ++i) {
        if (A % i == 0) {
            a += i;
        }
    }

    for (int i = 1; i < B; ++i) {
        if (B % i == 0) {
            b += i;
        }
    }

    cout << (a == B && b == A ? "yes\n" : "no\n");

    return 0;
}