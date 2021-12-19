#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        vector<int> a(n, 1);
        for (int i = 1; i < n; ++i) {
            if (prices[i - 1] - 1 == prices[i]) {
                a[i] += a[i - 1];
            }
        }
        return accumulate(a.begin(), a.end(), 0ll);
    }
};

int main() { return 0; }