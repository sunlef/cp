#include<ctime>
#include<iostream>
using namespace std;

using namespace std;
int main(){
    srand(time(0));

    int n = rand() % 3 + 1;
    bool visted[201];

    int k = rand() % n + 1;
    
    cout << n << " " << k << endl;

    for(int i = 1; i <= k; ++i){
        int a = rand() % (2*n) + 1;
        int b = rand() % (2*n) + 1;
        while(visted[a] || visted[b] || a == b){
            a = rand() % (2*n) + 1;
            b = rand()%(2*n) + 1;
        }  
        visted[a] = visted[b] = true;
        cout << a << " " << b << endl;
    }

}