#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;

        v.push_back(nums[0]);

        for (int i = 1; i < n; i++) {
            if (v[v.size() - 1] <= nums[i]) {
                v.push_back(nums[i]);
            } else if (v[v.size() - 1] > nums[i]) {
                auto it = upper_bound(v.begin(), v.end(), nums[i]);
                *it = nums[i];
            }
        }

        return v.size();
    }

    int kIncreasing(vector<int>& arr, int k) {
        int n = arr.size();

        vector<vector<int>> vec(k, vector<int>());
        for (int i = 0; i < n; ++i) {
            vec[i % k].push_back(arr[i]);
        }

        int res = 0;
        for (auto& row : vec) {
            res += int(row.size()) - lengthOfLIS(row);
        }

        return res;
    }
};

int main() {

    vector<int> a = {4, 1, 5, 2, 6, 2};
    Solution sol;
    cout << sol.kIncreasing(a, 3) << endl;

    return 0;
}