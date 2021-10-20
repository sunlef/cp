#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
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
int a[100005];//存1的位置
int b[100005];//存当前位置左边的第一个1的位置
string pre[100005];
const string lim = "FFFFFF";
int idx;
//两个16进制数相加
char s[6]={'A','B','C','D','E','F'};
string minn(string a, string b) {
    if(stoi(a)<stoi(b))return a;
    return b;
}
string add(string a, string b) {
    int n1 = stoi(a.substr(0,1))+stoi(b.substr(0,1));if(n1>=255)n1=255;
    string s1; int a1 = n1/16, b1 = n1%16;
    if(a1>=10) s1+=s[a1-10]; else s1+=('0'+a1);
    if(a1>=10) s1+=s[b1-10]; else s1+=('0'+b1);
    
    int n2 = stoi(a.substr(2,3))+stoi(b.substr(2,3));if(n2>=255)n2=255;
    string s2; int a2 = n2/16, b2 = n2%16;
    if(a2>=10) s2+=s[a2-10]; else s2+=('0'+a2);
    if(a2>=10) s2+=s[b2-10]; else s2+=('0'+b2);

    int n3 = stoi(a.substr(4,5))+stoi(b.substr(4,5));if(n3>=255)n3=255;
    string s3; int a3 = n3/16, b3 = n3%16;
    if(a3>=10) s3+=s[a3-10]; else s3+=('0'+a3);
    if(a3>=10) s3+=s[b3-10]; else s3+=('0'+b3);
    
    return s1+s2+s3;
}
string minuss(string a, string b) {
    int n1 = stoi(a.substr(0,1))-stoi(b.substr(0,1));if(n1>=255)n1=255;
    string s1; int a1 = n1/16, b1 = n1%16;
    if(a1>=10) s1+=s[a1-10]; else s1+=('0'+a1);
    if(a1>=10) s1+=s[b1-10]; else s1+=('0'+b1);
    
    int n2 = stoi(a.substr(2,3))-stoi(b.substr(2,3));if(n2>=255)n2=255;
    string s2; int a2 = n2/16, b2 = n2%16;
    if(a2>=10) s2+=s[a2-10]; else s2+=('0'+a2);
    if(a2>=10) s2+=s[b2-10]; else s2+=('0'+b2);

    int n3 = stoi(a.substr(4,5))-stoi(b.substr(4,5));if(n3>=255)n3=255;
    string s3; int a3 = n3/16, b3 = n3%16;
    if(a3>=10) s3+=s[a3-10]; else s3+=('0'+a3);
    if(a3>=10) s3+=s[b3-10]; else s3+=('0'+b3);
    
    return s1+s2+s3;
}
void solve() {
    int n,q;cin>>n>>q;
    int mode; string col;
    for(int i=1;i<=n;i++) {
        cin >> mode >> col;
        if(mode == 1) a[++idx]=i;
        b[i] = a[idx];
        if(mode == 1) {
            pre[i] = col;
        } else {
            pre[i] = add(pre[i],col);
        }
    }
    while(q--) {
        int l,r;
        cin>>l>>r;
        if(b[l]==b[r]) printf("%x\n",minn(lim,minuss(pre[r],pre[l-1])));
        else printf("%X\n",pre[r]);
    }
    
}
int main(){
    //srand(time(NULL) * time(NULL));
    ios::sync_with_stdio(false); cin.tie(0);
    int t ; cin >> t; while(t--)
    solve(); return 0;
}