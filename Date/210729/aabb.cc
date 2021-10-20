#include <iostream>
#include <cstring>
#include <unordered_set>
using namespace std;

int f[5001][50001];
bool visted[5001][5001];
int SG(int a, int b){
    if(visted[a][b]) return f[a][b];
    if(a == 0 && b == 0) { 
        visted[a][b] = true; 
        return f[a][b] = false;
    }

    unordered_set<int> s;
    for(int i = 1; i <= a; ++i)
        for(int j = 0; j*i <= b; ++j)
            s.insert(SG(a-i, b-i*j));
    for(int i = 1; i <= b; ++i)
        for(int j = 0; j*i <= a; ++j)
            s.insert(SG(a-i*j, b-i));
    
    for(int i = 0; ; ++i) if(!s.count(i)) return f[a][b] = i;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;
        if(SG(n,m) == 0) cout << "Bob" << endl;
        else cout << "Alice" << endl;
    }
}