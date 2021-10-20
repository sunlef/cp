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

base_pow bp = 6;
string_hash sh = {"114514", bp};
auto T = sh.sub(1, 6);

void solve() {
    string S;
    cin >> S;
    string_hash L = {S, bp};
    for (int i = 0; i + 5 < S.size(); ++i) {
        if (L.sub(i + 1, i + 6) == T) {
            cout << "AAAAAA\n";
            return;
        }
    }
    cout << "Abuchulaile\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cout << is_same<size_t, uint32_t>::value << endl;
    int T;
    cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        solve();
    }

    return 0;
}