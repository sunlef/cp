#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<int, int> mp;
    mp[22] = 1;
    mp[12342] = 12334;

    for (map<int, int>::iterator i = mp.begin(); i != mp.end(); ++i) {
        cout << i->first << '\n';
    }

    return 0;
}