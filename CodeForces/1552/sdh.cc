#include<iostream>
#include<vector>
#include<cmath>
typedef long long LL;
typedef unsigned long long ULL;
#define rep(i,a,b) for(int i = a; i <= b; i ++)
#define pb(x) emplace_back(x)
#define deb(x) std::clog << (#x) << " = " << (x) << '\n';
#define PII pair<int,int>
#define endl '\n'
#define cd complex<double>
const double PI = acos(-1.0);
using namespace std;
const int N=205;
bool st[N];
void solve() {
    int n,k;cin>>n>>k;
    vector<PII>v;
    memset(st,0,sizeof st);
    for(int i=1;i<=k;i++) {
        int a,b;cin>>a>>b;
        if(a>b)swap(a,b);
        v.push_back({a,b});
        st[a]=1;st[b]=1;
    }
    vector<int>s;
    for(int i =1;i<=2*n;i++) {
        if(!st[i])s.pb(i);
    }
    int tt = s.size()/2;
    sort(s.begin(),s.end());
    for(int i=0;i<tt;i++) {
        v.push_back({s[i],s[i+tt]});
    }
    int ans = 0;
    for(auto i:v) {
        int a=i.first,b=i.second;
        for(auto j:v) {
            if(j.first<a&&j.second>a&&j.second<b) {
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}
int main(){
    //srand(time(NULL) * time(NULL));
    ios::sync_with_stdio(false); cin.tie(0);
    int t = 1 ; /*cin >> t*/; while(t--)
    solve(); return 0;
}