#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> ans = {2, 3, 5, 9, 17, 33, 65, 129, 257, 513, 1025, 2049};
    int N;
    cin >> N;

    cout << ans[N] << '\n';

    return 0;
}