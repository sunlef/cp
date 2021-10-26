#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int cnt1 = 0, cnt2 = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x == 1) {
            ++cnt1;
        } else {
            ++cnt2;
        }
    }

    int now = 0;
    vector<int> ans;
    while (cnt1 || cnt2) {
        if (ans.size()) {
            now += *ans.rbegin();
        }
        if (now == 0) {
            if (cnt2) {
                ans.push_back(2);
                --cnt2;
            } else if (cnt1) {
                ans.push_back(1);
                --cnt1;
            }
        } else {
            if (now & 1) {
                if (cnt2) {
                    ans.push_back(2);
                    --cnt2;
                } else if (cnt1) {
                    ans.push_back(1);
                    --cnt1;
                }
            } else {
                if (cnt1) {
                    ans.push_back(1);
                    --cnt1;
                } else if (cnt2) {
                    ans.push_back(2);
                    --cnt2;
                }
            }
        }
    }

    for (auto &x : ans) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}