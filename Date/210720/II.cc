#include<iostream>
#include<map>
#include<cmath>
typedef long long LL;
#define deb(x) std::clog << (#x) << " = " << (x) << '\n';
#define PII pair<int,int>
#define endl '\n'
#define cd complex<double>
const double PI = acos(-1.0);
using namespace std;
const int N = 550005;
int p[N];
int find(int x) {
    if(p[x]!=x)p[x]=find(p[x]);
    return p[x];
}
void solve() {
    int n, m, k; cin >> n >> m >> k;
    for(int i = 1;i <= n;i++) p[i] = i;
    map<LL,LL>mp;
    while(m--) {
        int a, b, w; cin >> a >> b >> w;
        if(!mp[w]) {
            mp[w] = a;
            p[find(b)] = a;
        } else {
            p[find(b)] = a;
            p[find(a)] = mp[w];
        }
    }
    LL cnt = 0;
    LL minl=2e9;
    for(auto i : mp) {
        if(i.second) cnt++;
        minl = min(i.first, minl);
    }
    if(cnt==k){
        cout<<minl<<endl;
    }else{
        cout<<-1<<endl;
    }
}
int main(){
    //srand(time(NULL) * time(NULL));
    ios::sync_with_stdio(false); cin.tie(0);
    int t ; cin >> t; while(t--)
    solve(); return 0;
}   
/*
   整理：
*/