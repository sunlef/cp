#include <bits/stdc++.h>
using namespace std;

template <class _data_class = int, int _base = 13331> constexpr uint64_t vector_hash(const vector<_data_class> &vec) {
    uint64_t res = 0;
    for (const auto element : vec) {
        res = _base * res + element + _base;
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> vec(n);
    for (auto &x : vec) {
        cin >> x;
    }
    cout << vector_hash<int, 2233>(vec) << '\n';

    return 0;
}
