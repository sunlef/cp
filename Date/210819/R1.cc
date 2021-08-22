#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string str[10001] = {"0", "http://www.acm.org/"};
    int i = 1;
    int t;
    string cmd, web;
    while(cin >> cmd) {
        if(cmd[0] == 'V') {
            i++;
            cin >> web;
            cout << web << endl;
            str[i] = web;
            t = i;
        }
        
        else if(cmd[0] == 'B') {
            i--;
            if(i == 0) {
                cout << "Ignored" << '\n';
                i = 1;
            } else cout << str[i] << '\n';
        }

        else if(cmd[0] == 'F') {
            ++i;
            if(i > t) {
                cout << "Ignored" << '\n';
                --i;
            } else cout << str[i] << '\n';
        }

        else if(cmd[0] == 'Q') {
            break;
        }
    }
    return 0;
}
