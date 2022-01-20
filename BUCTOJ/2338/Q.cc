#include <bits/stdc++.h>
using namespace std;

int N, M;

void solve() {
    list<int> L(M);
    vector<list<int>::iterator> pointers(M + 1);

    int idx = 1;
    for (auto i = L.begin(); i != L.end(); ++i) {
        *i = idx++;
        pointers[idx - 2] = i;
    }

    bool reversed = false;
    while (N--) {
        int op;
        cin >> op;

        if (op == 1) {
            int x, y;
            cin >> x >> y;
            --x, --y;

            auto ptr1 = pointers[x];
            pointers[x] = L.insert(pointers[y], *ptr1);
            L.erase(ptr1);

            if (reversed) {
                swap(*pointers[x], *pointers[y]);
                swap(pointers[x], pointers[y]);
            }
        } else if (op == 2) {
            int x, y;
            cin >> x >> y;
            --x, --y;

            auto ptr1 = pointers[x];
            pointers[x] = L.insert(pointers[y], *ptr1);
            L.erase(ptr1);

            if (!reversed) {
                swap(*pointers[x], *pointers[y]);
                swap(pointers[x], pointers[y]);
            }
        } else if (op == 3) {
            int x, y;
            cin >> x >> y;
            --x, --y;

            swap(*pointers[x], *pointers[y]);
            swap(pointers[x], pointers[y]);
        } else {
            reversed = !reversed;
        }
    }

    int64_t ans = 0;

    auto ptr = L.begin();
    if (reversed) {
        ptr = --L.end();
    }

    for (int i = 0; i < int(L.size()); i++) {
        if (i % 2 == 0) ans += *ptr;
        if (!reversed)
            ptr++; 
        else if (ptr != L.begin())
            ptr--;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    while (cin >> M >> N) {
        cout << "Case " << T++ << ": ";
        solve();
    }

    return 0;
}