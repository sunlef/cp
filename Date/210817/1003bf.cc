#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; ++i)
        cin >> a[i];

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
        int score = a[xx] + b[1];
        vector<int> geq, l;
        for(int i = 1; i <= n; ++i) {
            if(i == xx) continue;
            if(a[i] > score) geq.emplace_back(a[i]);
            else l.emplace_back(a[i]);
        }
        vector<int> vec;
        int idx = 1;
        for(auto &x : geq) {
            vec.emplace_back(x + bn1[idx++]);
        }
        int tail = n - 1;
        sort(l.begin(), l.end(), greater<int>());
        for(auto &x : l) {
            int plus_min = x + bn1[tail];
            if(tail == idx) {
                vec.emplace_back(plus_min);
            } else if(plus_min <= score) {
                vec.emplace_back(plus_min);
                tail--;
            } else {
                vec.emplace_back(x + bn1[idx++]);
            }
        }
        vec.emplace_back(score);
        sort(vec.begin(), vec.end(), greater<int>());
        debug();
        for(auto &x : vec)
            cout << x << " ";
        cout << endl; 
        return lower_bound(vec.begin(), vec.end(), score, greater<int>()) - vec.begin() + 1;
    };

    auto calc_worst = [&] (int xx) {
        int score = a[xx] + b[n];
        vector<int> geq, l;
        for(int i = 1; i <= n; ++i) {
            if(i == xx) continue;
            if(a[i] >= score) geq.emplace_back(a[i]);
            else l.emplace_back(a[i]);
        }
        vector<int> vec;
        int head = 1, tail = n - 1;
        sort(l.begin(), l.end());
        for(auto &x : l) {
            int plus_max = x + bnn[head];
            if(head == tail) {
                vec.emplace_back(plus_max);
            } else if(plus_max > score) {
                vec.emplace_back(plus_max);
                head++;
            } else {
                vec.emplace_back(x + bnn[tail--]);
            }
        }
        for(auto &x : geq) {
            vec.emplace_back(x + bnn[head++]);
        }
        vec.emplace_back(score);
        sort(vec.begin(), vec.end(), greater<int>());
       /*  debug();
        for(auto &x : vec)
            cout << x << " ";
        cout << endl; */
        return lower_bound(vec.begin(), vec.end(), score, greater<int>()) - vec.begin() + 1;
    };
    
    for(int i = 1; i <= n; ++i)
        cout << calc_best(i) << " " << calc_worst(i) << '\n';
        
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