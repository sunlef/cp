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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    while (cin >> N && N) {
        cin >> Q;
        
        vector<int> A(N);
        for (int &i : A) {
            cin >> i;
        }

        vector<int> freq(N);

        for (int i = 0; i < N; ++i) {
            if (i == 0 || A[i] != A[i - 1]) {
                freq[i] = 1;
            } else {
                freq[i] = freq[i - 1] + 1;
            }
        }

        ST st(freq);

        while (Q--) {
            int l, r;
            cin >> l >> r;
            --l, --r;

            int pos = upper_bound(A.begin(), A.end(), A[l]) - A.begin();
            if (pos > r) {
                cout << r - l + 1 << '\n';
            } else {
                cout << max(pos - l, st.query(pos, r + 1)) << '\n';
            }
        }
    }

    return 0;
}