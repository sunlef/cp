#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;

    while (cin >> N) {
        if (N == 0) {
            break;
        }
        vector<int> A(N);
        for (int &i : A) {
            cin >> i;
        }
        sort(A.begin(), A.end());

        for (int i : A) {
            cout << i << ' ';
        }
        cout << '\n';
    }

    return 0;
}