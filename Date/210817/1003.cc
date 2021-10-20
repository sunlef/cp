#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i+1;
    }
    a.emplace_back(make_pair(-1,-1));
    sort(a.begin(), a.end());

    debug(a);
    vector<int> b(n+1);
    for(int i = 1; i <= n; ++i)
        cin >> b[i];
    
    vector<int> bn1, bnn;
    bn1.emplace_back(0), bnn.emplace_back(0);
    for(int i = 1; i <= n; ++i) {
        if(i != 1) bn1.emplace_back(b[i]);
        if(i != n) bnn.emplace_back(b[i]);
    }

    auto calc_best = [&] (int xx) {
        int score = a[xx].first + b[1];
        int res = 1;
        vector<int> l;
        int head = 1, tail = n - 1;
        for(int i = n; i >= 1; --i) {
            if(i == xx) {
                continue;
            }
            if(a[i].first < score) {
                l.emplace_back(a[i].first);
            } else {
                ++res;
                ++head;
            }
        }
        for(auto &x : l) {
            int plus_min = x + bn1[tail];
            if(plus_min > score) {
                ++head;
                ++res;
            } else {
                --tail;
            }
        }
        return res;
    };

    auto calc_worst = [&] (int xx) {
        int score = a[xx].first + b[n];
        int res = 1;
        vector<int> l;
        int head = 1, tail = n - 1;
        for(int i = 1; i <= n; ++i) {
            if(i == xx) {
                continue;
            }
            if(a[i].first < score) {
                l.emplace_back(a[i].first);
            } else {
                ++res;
                --tail;
            }
        }
        for(auto &x : l) {
            int plus_max = x + bnn[head];
            if(plus_max > score) {
                ++res;
                ++head;
            } else {
                --tail;
            }
        }
        return res;
    };

    while(1) {
        int x;
        cin >> x;
        cout << a[x].second << ": " <<  calc_best(x) << ' ' << calc_worst(x) << endl;
    }

  
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