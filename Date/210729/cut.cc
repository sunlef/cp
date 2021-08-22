#include<iostream>
#include<set>
#include<cstring>
using namespace std;

int f[201][201];

int SG(int n, int m){
    if(f[n][m] != -1) return f[n][m];
    if(f[m][n] != -1) return f[n][m] = f[m][n];

    set<int> S;
    for(int i = 2; i < n - 1; ++i) S.insert(SG(i, m) ^ SG(n-i, m));
    for(int j = 2; j < m - 1; ++j) S.insert(SG(n, j) ^ SG(n, m-j));

    for(int i = 0; ; ++i) if(!S.count(i)) return f[n][m] = i;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    memset(f, -1, sizeof f);
    f[2][2] = f[2][3] = f[3][2] = 0;
    int n, m;
    while(cin >> n >> m){
        if(SG(n, m) > 0) cout << "WIN" << '\n';
        else cout << "LOSE" << '\n';
    }
    return 0;
}