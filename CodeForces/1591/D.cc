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

int64_t calc_pairs(const vector<int> &a) {
    fenwick<int> fen(a.size());
    int64_t res = 0;
    for (int x : a) {
        res += fen.query(a.size()) - fen.query(x);
        fen.add(x, 1);
    }
    return res;
}


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }

    if (int(set(a.begin(), a.end()).size()) < n || calc_pairs(a) % 2 == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        solve();
    }

    return 0;
}