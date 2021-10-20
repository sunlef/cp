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

template<typename T>
struct prime { //线性筛
    T max_num;
    vector<T> primes;
    vector<int> visted;
    prime(T max_num) : max_num(max_num), primes(), visted(max_num+1, 0) {
        for(T i = 2; i <= max_num; ++i) {
            if(!visted[i])
                primes.emplace_back(i);
            for(T j = 0; j < primes.size() && (__int128_t) (primes[j] * i) <= max_num ; ++j) {
                visted[primes[j] * i] = 1;
                if(i % primes[j] == 0) break;
            }
        }
    }
    bool is_prime(T x) {
        if(x < 2 || x > max_num) return false;
        return !visted[x];
    }
};