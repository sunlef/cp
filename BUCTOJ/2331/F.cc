#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    while (cin >> n) {
        function<double(int)> f = [&](int x) {
            if (x == 0) {
                return sin(double(n));
            } else {
                return sin(f(x - 1));
            }
        };

        cout << fixed << setprecision(6) << f(n) << '\n';
    }

    return 0;
}