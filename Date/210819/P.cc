#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> pos(200001, -1);
    int q;
    cin >> q;
    int nowl = 0, nowr = 0;
    while(q --) {
        char op;
        int id;
        cin >> op >> id;
        if(op == 'L') {
            pos[id] = --nowl;
        } else if(op == 'R') {
            pos[id] = ++nowr;
        } else {
            int p = pos[id];
            if(p < 0) {
                cout << min(p - nowl, nowr - p - 1) << '\n';
            } else {
                cout << min(nowr - p, p - nowl - 1) << '\n';
            }
        }
    }

    return 0;
}
