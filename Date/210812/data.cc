#include <bits/stdc++.h>
using namespace std;

void solve(){
    cout << 10 << endl;
    int n = 10;
    while(n--){
    int t = (rand() * rand()) % 51;
    if(t < 0) t += 51;
    cout << t << " ";

    t = ((rand() * rand())) % 899;
    t -= 495;
    if(t < -495) t += 899;
    cout << t << " ";

    t = rand() * rand() % 899;
    t -= 495;
    if(t < -495) t += 899;
    cout << t << endl;

    t = rand() * rand() % 51;
    if(t < 0) t += 51;
    cout << t << " ";

    t = rand() * rand() % 899;
    t -= 495;
    if(t < -495) t += 899;
    cout << t << " ";

    t = rand() * rand() % 899;
    t -= 495;
    if(t < -495) t += 899;
    cout << t << endl;

    t = rand() * rand() % 40;
    if(t < 0) t += 40;
    t += 1;
    cout << t << endl;
    }
}

int main() {
   
    srand(time(0) * time(0));

    solve();

    return 0;
}