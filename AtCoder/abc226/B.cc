#include <bits/stdc++.h>
using namespace std;

template <class _data_class = int, int _base = 13331> constexpr uint64_t vector_hash(const vector<_data_class> &vec) {
    uint64_t res = 0;
    for (const auto element : vec) {
        res = _base * (uint64_t(element) + res + _base);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    set<uint64_t> s;
    int n;
    cin >> n;
    while (n--) {
        int l;
        cin >> l;
        vector<int> a(l);
        for (auto &x : a) {
            cin >> x;
        }
        s.insert(vector_hash(a));
    }

    cout << s.size() << '\n';
    
    return 0;
}