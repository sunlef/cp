#include <bits/stdc++.h>
using namespace std;

void solve(){

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned _TvT_;
    cin >> _TvT_;
    for(unsigned i = 1; i <= _TvT_; ++i){
        solve();
    }

    return 0;
}

struct Trie{
    int max_idx;
    int idx;
    std::vector<std::vector<int>> son;
    std::vector<int> is_end;
    Trie(int total_len, int char_set) : 
        max_idx(total_len + 1), idx(0),
        son(max_idx, std::vector<int>(char_set, 0)), 
        is_end(max_idx, 0) {}
    Trie(int n, int per_len, int char_set) : Trie(n * per_len, char_set) {}
    void insert(const string &str) {
        int p = 0;
        for(auto &ch : str) {
            int b = ch - 'a';
            if(son[p][b] == 0) son[p][b] = ++idx;
            p = son[p][b];
        }
        is_end[p]++;
    }
    bool query(const string &str) {
        int p = 0;
        for(auto &ch : str) {
            int b = ch - 'a';
            if(son[p][b] == 0) return false;
            p = son[p][b];
        }
        return is_end[p];
    }
};
