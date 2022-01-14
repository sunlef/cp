#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;

    vector<int> a(N);
    for (int &i : a) {
        cin >> i;
    }

    map<int, int> mp;
    for (int i : a) {
        ++mp[i];
    }

    sort(a.begin(), a.end());

    int MAX = INT_MIN;
    for (int i : a) {
        MAX = max(MAX, mp[i]);
    }

    for (int i : a) {
        if (MAX == mp[i]) {
            cout << i << '\n';
            return 0;
        }
    }

    return 0;
}