#include <iostream>
#include <unordered_set>
using namespace std;

int f[1000][1000][2];

int SG(int a, int take_limit, bool first){
    if(take_limit > a) take_limit = a;
    if(f[a][take_limit][first] != -1) return f[a][take_limit][first];
    if(a == 0) return f[a][take_limit][first] = 0;

    unordered_set<int> s;
    if(first){
        for(int i = 1; i < a; ++i) 
            s.insert(SG(a-i, 2*i, false));
    }
    else {
        for(int i = 1; i <= min(take_limit, a); ++i) 
            s.insert(SG(a-i, 2*i, false));
    }

    for(int i = 0; ; ++i) if(!s.count(i)) return f[a][take_limit][first] = i;
}

int main(){
    memset(f, -1, sizeof f);

    for(int i = 2; i <= 999; ++i)
        if(SG(i,0x3f3f3f3f,true) == 0)
            cout << i << endl;

    return 0;
}