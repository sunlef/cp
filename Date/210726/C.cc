#include<iostream>
using namespace std;
using PII = pair<int,int>;
PII aa[5];
int n;
void solve() {
    for(int i = 1; i <= 3; ++i){
        cin >> aa[i].first;
        aa[i].second = i;
    }

    sort(aa+1, aa+4);
    int a = aa[1].first;
    int b = aa[2].first;
    int c = aa[3].first;
    cin >> n;

    string s1(a,'a');
    string s2(b,'a');
    string s3(b,'a');
    if(n-s3.length()<c-a){
        cout<<"NO"<<endl;
        return;
    }
    for(int i=0;i<c-a;i++) {
        s1+='b';
        s3+='b';
    }
    for(int i=s1.length();i<n;i++) {
        s1+='x';
    }
    for(int i=s2.length();i<n;i++) {
        s2+='y';
    }
    for(int i=s3.length();i<n;i++) {
        s3+='z';
    }

    string s[4]; s[1] = s1, s[2] = s2, s[3] = s3;
    string ans[4];
    for(int i = 1; i <= 3; ++i)  ans[aa[i].second]  = s[i];
    for(int i = 1; i <= 3; ++i) cout << ans[i] << endl;
    
    
}
int main(){
    //srand(time(NULL) * time(NULL));
    ios::sync_with_stdio(false); cin.tie(0);
    //int t ; cin >> t; while(t--)
    solve(); return 0;
}