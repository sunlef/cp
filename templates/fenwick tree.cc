//https://www.luogu.com.cn/problem/P3374

#include <bits/stdc++.h>
using namespace std;

template <typename T> struct fenwick {
    private:
    int n;
    std::vector<T> c;

    public:
    fenwick(int n) : n(n + 1), c(n + 1) {}
    void add(int pos, T val) {
        for (; pos < n; pos += pos & -pos) c[pos] += val;
    }
    T query(int pos) {
        T res = 0;
        for (; pos; pos -= pos & -pos) res += c[pos];
        return res;
    }
};


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    fenwick<long long> fen(n);

    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        fen.add(i, x);
    }

    while (m--) {
        int op, x, y;
        cin >> op >> x >> y;
        if(op == 1) {
            fen.add(x, y);
        } else {
            cout << fen.query(y) - fen.query(x - 1) << '\n';
        }
    }
    
    return 0;
}