#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string x;

    while (cin >> x) {
        if (x.size() <= 2) {
            int n = 0;
            reverse(x.begin(), x.end());
            int base = 1;
            for (int i = 0; i < int(x.size()); ++i) {
                n += base * (x[i] - '0');
                base *= 10;
            }

            function<double(int)> f = [&](int x) {
                if (x == 0) {
                    return cos(double(n));
                } else {
                    return cos(f(x - 1));
                }
            };

            cout << fixed << setprecision(6) << f(n) << '\n';
        } else {
            cout << "0.739085\n";
        }
    }

    return 0;
}