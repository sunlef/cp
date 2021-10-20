//https://www.luogu.com.cn/problem/P3370

#include <bits/stdc++.h>
using namespace std;

struct base_pow {
    int N, base;
    vector<uint64_t> val;

    base_pow(int _N, int _base = 13331) : N(_N), base(_base), val(N + 1, 1) {
        for (int i = 1; i <= N; ++i) {
            val[i] = base * val[i - 1];
        }
    }
};

struct string_hash {
    int N, base;
    vector<uint64_t> pre;
    vector<uint64_t>::const_iterator it_begin;

    string_hash(const string &str, const base_pow &bp, int _base = 13331)
        : N(int(str.size())), base(_base), pre(int(str.size()) + 1, 0), it_begin(bp.val.begin()) {
        for (int i = 1; i <= N; ++i) {
            pre[i] = base * pre[i - 1] + str[i - 1] + base;
        }
    }

    uint64_t sub(int l, int r) {
        assert(l >= 1 && r <= N);
        return pre[r] - pre[l - 1] * *(it_begin + r - l + 1);
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    set<uint64_t> s;
    int N;
    cin >> N;

    base_pow bp(1500);

    while (N--) {
        string str;
        cin >> str;
        s.insert(string_hash(str, bp).sub(1, str.size()));
    }

    cout << int(s.size()) << '\n';

    return 0;
}