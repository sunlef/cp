#include <bits/stdc++.h>
using namespace std;

template <class T> struct ST {
    int n;
    vector<vector<T>> info;

    T merge(const T &lhs, const T &rhs) {
        // TODO: 修改merge
        return std::max(lhs, rhs);
    }

    ST(const vector<T> &init) : n(int(init.size())), info(n + 1, vector<T>(__lg(n) + 1, INT_MIN)) {
        //TODO : 修改初值
        for (int x = 0; x <= __lg(n); ++x)
            for (int i = 0; i + (1 << x) <= n; ++i)
                if (x == 0) info[i][x] = init[i];
                else        info[i][x] = merge(info[i][x - 1], info[i + (1 << (x - 1))][x - 1]);
    }

    T query(int l, int r) {  //[l, r)
        int len = r - l;
        assert(len > 0);
        return merge(info[l][__lg(len)], info[r - (1 << __lg(len))][__lg(len)]);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> a(N);
    for (auto &x : a) {
        cin >> x;
    }

    ST s(a);
    while (M--) {
        int l, r;
        cin >> l >> r;
        --l;
        cout << s.query(l, r) << '\n';
    }

    return 0;
}