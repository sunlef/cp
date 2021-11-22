#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    auto query = [&](int l, int r) {
        cout << "? " << l << ' ' << r << endl;
        int res;
        cin >> res;
        return res;
    };

    int lst = query(1, n);

    if (lst != 1 && query(1, lst) == lst) {
        int l = 1, r = lst - 1;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            int now = query(mid, lst);
            if (now == lst) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        cout << "! " << r << endl;
    } else {
        int l = lst + 1, r = n;
        while (l < r) {
            int mid = (l + r) / 2;
            int now = query(lst, mid);
            if (now == lst) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        cout << "! " << r << endl;
    }

    return 0;
}