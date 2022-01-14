//https://www.luogu.com.cn/problem/P2580

#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    cin >> n;

    struct trie {
        int max_idx;
        int idx;
        std::vector<std::vector<int>> son;
        std::vector<int> is_end;
        std::vector<int> visted;
        trie(int total_len, int char_set) : max_idx(total_len + 1), idx(0), son(max_idx, std::vector<int>(char_set, 0)), is_end(max_idx, 0), visted(max_idx, 0) {}
        trie(int n, int per_len, int char_set) : trie(n * per_len, char_set) {}
        void insert(const string &str) {
            int p = 0;
            for (auto &ch : str) {
                int b = ch - 'a';
                if (son[p][b] == 0) son[p][b] = ++idx;
                p = son[p][b];
            }
            is_end[p]++;
        }
        int query(const string &str) {
            int p = 0;
            for (auto &ch : str) {
                int b = ch - 'a';
                if (son[p][b] == 0) return -1;
                p = son[p][b];
            }
            if (!is_end[p]) return -1;
            if (!visted[p]) {
                return visted[p] = 1;
            } else {
                return 0;
            }
        }
    };

    trie tr(n, 50, 26);

    for(int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        tr.insert(s);
    }

    int m;
    cin >> m;
    while (m--) {
        string s;
        cin >> s;
        int t = tr.query(s);
        if(t == -1) {
            cout << "WRONG" << '\n';
        } else if(t == 0) {
            cout << "REPEAT" << '\n';
        } else {
            cout << "OK" << '\n';
        }
    }
    
    return 0;
}