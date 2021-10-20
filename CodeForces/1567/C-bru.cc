#include <bits/stdc++.h>
using namespace std;

int calc(int A, int B) {
    string a = to_string(A);
    string b = to_string(B);

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    if (b.size() > a.size()) {
        swap(a, b);
    }

    vector<int> res(a.size() + 10, 0);
    for (int i = 0; i < a.size(); ++i) {
        if (i < b.size()) {
            int aa = a[i] - '0';
            int bb = b[i] - '0';
            res[i] += aa + bb;
            if (res[i] >= 10) {
                res[i + 2]++;
                res[i] %= 10;
            }
        } else {
            int aa = a[i] - '0';
            res[i] += aa;
            if (res[i] >= 10) {
                res[i + 2]++;
                res[i] %= 10;
            }
        }
    }

    bool flag = false;
    int RES = 0;
    for (int i = a.size() + 9; i >= 0; --i) {
        if (!flag) {
            if (res[i] == 0) {
                continue;
            } else {
                flag = true;
                RES = res[i];
            }
        } else {
            RES = 10 * RES + res[i];
        }
    }

    return RES;
}

int solve(int n) {
    int ans = 0;
    for (int i = 1; i <= n + 5; ++i) {
        for (int j = 1; j <= n + 5; ++j) {
            if (calc(i, j) == n) {
                ++ans;
            }
        }
    }
    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cout << "LOL[101] = {0, ";
    for (int i = 2; i <= 100; ++i) {
        cout << solve(i);
        if (i != 100) {
            cout << ", ";
        } else {
            cout << "};" << '\n';
        }
    }

    return 0;
}