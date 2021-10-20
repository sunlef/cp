#include <bits/stdc++.h>
using namespace std;

template <typename T_vector> void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++) cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}

int main() {
    int n;
    cin >> n;

    vector<int> d(n + 1), a(n + 1), ans(n + 1);

    auto query1 = [&](int x) {
        cout << "? ";
        for (int i = 1; i <= n; ++i) {
            if (i == x) {
                cout << "2 ";
            } else {
                cout << "1 ";
            }
        }
        cout << endl;

        int idx;
        if (cin >> idx; idx != 0 && idx < x) {
            ++d[idx];
            a[x] = idx;
        }
    };

    auto query2 = [&](int x) {
        cout << "? ";
        for (int i = 1; i <= n; ++i) {
            if (i == x) {
                cout << "1 ";
            } else {
                cout << "2 ";
            }
        }
        cout << endl;

        int idx;
        if (cin >> idx; idx != 0 && idx < x) {
            ++d[x];
            a[idx] = x;
        }
    };

    for (int i = 1; i <= n; ++i) {
        query1(i);
        query2(i);
    }

    int idx = 0;
    for (int i = 1; i <= n; ++i) {
        if (d[i] == 0) {
            idx = i;
            break;
        }
    }

    ans[idx] = 1;
    while (a[idx]) {
        ans[a[idx]] = ans[idx] + 1;
        idx = a[idx];
    }

    cout << "! ";
    output_vector(ans, 0, 1);

    return 0;
}