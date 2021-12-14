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

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }

    auto b = a;
    sort(b.begin(), b.end());

    b.erase(unique(b.begin(), b.end()), b.end());
    for (auto &x : a) {
        x = lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
    }

    reverse(a.begin(), a.end());

    auto mx = *max_element(a.begin(), a.end());

    int64_t ans = 0;
    fenwick<int> fen(mx);

    for(const auto &x : a) {
        ans += fen.query(x - 1);
        fen.add(x, 1);
    }

    cout << ans << '\n';

    return 0;
}