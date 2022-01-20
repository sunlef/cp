#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

struct ST {
    size_t n;
    std::vector<std::vector<int>> info;

    int merge(const int &lhs, const int &rhs) {  // TODO: 修改merge
        return std::max(lhs, rhs);
    }

    ST(const std::vector<int> &init) : n(init.size()), info(init.size() + 1, std::vector<int>(std::__lg(n) + 1, INT_MIN)) {  //TODO : 修改初值
        for (size_t x = 0; x <= std::__lg(n); ++x)
            for (int i = 0; i + (1ull << x) <= n; ++i)
                if (x == 0)
                    info[i][x] = init[i];
                else
                    info[i][x] = merge(info[i][x - 1], info[i + (1 << (x - 1))][x - 1]);
    }

    int query(int l, int r) {  //[l, r)
        int len = r - l;
        assert(len > 0);
        return merge(info[l][std::__lg(len)], info[r - (1 << std::__lg(len))][std::__lg(len)]);
    }
};

int N, K;

void solve() {
    vector<int> V(N);
    for (int &i : V) {
        cin >> i;
    }

    if (accumulate(V.begin(), V.end(), 0ll) <= K) {
        cout << "-1\n";
        return;
    }

    ST st(V);

    for (int i = 1; i <= N; ++i) {
        int sum = 0;
        int len = N / i;
        for (int j = 0; j + len - 1 < N; j += len) {
            sum += st.query(j, j + len);
        }
        if (sum > K) {
            cout << i << '\n';
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> N >> K && !(N == -1 && K == -1)) {
        solve();
    }

    return 0;
}