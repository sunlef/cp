#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    priority_queue<int64_t, vector<int64_t>, greater<int64_t>> heap;

    int64_t ans = 0;

    for (int i = 0; i < N; ++i) {
        int64_t x;
        cin >> x;
        heap.push(x);
    }

    while (heap.size() > 1) {
        int64_t A = heap.top();
        heap.pop();
        int64_t B = heap.top();
        heap.pop();
        ans += A + B;
        heap.push(A + B);
    }

    cout << ans << '\n';

    return 0;
}