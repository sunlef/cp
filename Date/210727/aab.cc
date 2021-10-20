#include <iostream>
using namespace std;

int f[201][201];
int SG(int n, int m){
    if(f[n][m] != -1) return f[n][m];
    if(n == 1 && m == 1) return f[n][m] = 1;
    
}

int main(){
    for(int i = 1; i <= 200; ++i)
        for(int j = 1; j <= 200; ++j)
            f[i][j] = -1;

    int N, M;
    while(cin >> N >> M){
        if(SG(N, M) != 0) cout << "WIN" << '\n';
        else cout << "LOSE" << '\n';
    }
}