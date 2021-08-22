#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int N, M, K;
vector<int> G[2001];
int f[2001];

int SG(int u){
    if(f[u] != -1) return f[u];
    if(G[u].size() == 0) return f[u] = 0;

    unordered_set<int> s;
    for(auto v : G[u]) s.insert(SG(v));
    for(int i = 0; ; ++i) if(!s.count(i)) return f[u] = i;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M >> K;
    for(int i = 1; i <= N; ++i) f[i] = -1;

    while(M--){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }

    int res = 0;
    while(K--){
        int x;
        cin >> x;
        res ^= SG(x);
    }

    if(res) cout << "win" << '\n';
    else cout << "lose" << '\n';

    return 0;
}