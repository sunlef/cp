#include <iostream>
using namespace std;

int main(){
    int T;
    cin >> T;
    
    while(T--){
        int n;
        int res = 0;
        while(n--){
            int x;
            cin >> x;
            res ^= x;
        }
        if(res) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}