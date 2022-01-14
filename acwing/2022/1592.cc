#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, X, Y, Z;
    cin >> N >> X >> Y >> Z;

    vector<int> nums;
    vector<pair<int, int>> cows(N);
    for (auto &[A, B] : cows) {
        cin >> A >> B;
        nums.push_back(A);
        nums.push_back(B);
    }

    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    int MAX = INT_MIN;
    for (auto &[A, B] : cows) {
        A = lower_bound(nums.begin(), nums.end(), A) - nums.begin() + 1;
        B = lower_bound(nums.begin(), nums.end(), B) - nums.begin() + 1;
        MAX = max(MAX, B);
    }

    vector<int> milk(MAX + 2);

    for (auto &[A, B] : cows) {
        milk[A] += Y - X;
        milk[B + 1] -= Y - Z;
    }

    for (int i = 1; i <= MAX; ++i) {
        milk[i] += milk[i - 1];
    }

    cout << *max_element(milk.begin(), milk.begin() + MAX + 1) + N * X << '\n';
    return 0;
}