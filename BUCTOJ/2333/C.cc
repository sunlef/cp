#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;

    while (cin >> N) {
        function<int(int)> f = [&](int x) -> int { return x < 5 ? 0 : x / 5 + f(x / 5); };
        cout << f(N) << '\n';
    }

    return 0;
}