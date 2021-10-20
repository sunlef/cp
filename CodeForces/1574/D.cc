#include <bits/stdc++.h>
using namespace std;

template <class _data_class = int, int _base = 13331>
constexpr uint64_t vector_hash(const vector<_data_class> &vec, const vector<vector<int>> &slot, int64_t &sum) {
    uint64_t res = 0;
    sum = 0;
    for (int i = 0; i < int(vec.size()); ++i) {
        res = _base * res + vec[i] + _base;
        sum += slot[i][vec[i] - 1];
    }
    return res;
}

template <typename T_vector> void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++) cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> SIZE(n, 0);
    vector<vector<int>> slot(n, vector<int>());

    for (int i = 0; i < n; ++i) {
        cin >> SIZE[i];
        for (int j = 0; j < SIZE[i]; ++j) {
            int strength;
            cin >> strength;
            slot[i].emplace_back(strength);
        }
    }

    int m;
    cin >> m;

    vector<int> NOW_BUILD(n), ANS_BUILD(n);
    vector<vector<int>> BAN_BUILD(m, vector<int>(n, 0));
    set<uint64_t> banned;

    int64_t sum;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> BAN_BUILD[i][j];
        }
        banned.insert(vector_hash(BAN_BUILD[i], slot, sum));
    }

    for (int i = 0; i < n; ++i) {
        NOW_BUILD[i] = SIZE[i];
    }

    if (!banned.count(vector_hash(NOW_BUILD, slot, sum))) {
        output_vector(NOW_BUILD);
        return 0;
    }

    int64_t ans = INT64_MIN;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            NOW_BUILD = BAN_BUILD[i];
            NOW_BUILD[j] = max(1, BAN_BUILD[i][j] - 1);
            if (!banned.count(vector_hash(NOW_BUILD, slot, sum)) && sum > ans) {
                ans = sum;
                ANS_BUILD = NOW_BUILD;
            }
        }
    }

    output_vector(ANS_BUILD);

    return 0;
}