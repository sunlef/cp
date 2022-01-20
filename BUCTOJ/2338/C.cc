#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B, C, D;
    while (cin >> A >> B >> C >> D) {
        if (A == B && C == D) {
            if (A > C) {
                cout << "A\n";
            } else if (A < C) {
                cout << "B\n";
            } else {
                cout << "N\n";
            }
        } else if (A != B && C != D) {
            if ((A + B) % 10 > (C + D) % 10) {
                cout << "A\n";
            } else if ((A + B) % 10 < (C + D) % 10) {
                cout << "B\n";
            } else {
                cout << "N\n";
            }
        } else if (A == B && C != D) {
            cout << "A\n";
        } else if (A != B && C == D) {
            cout << "B\n";
        } else {
            cout << "N\n";
        }
    }

    return 0;
}