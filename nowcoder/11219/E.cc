#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

void solve() {
    priority_queue<i64> max_heap;
    priority_queue<i64, vector<i64>, greater<i64>> min_heap;

    i64 a, b, c, N;
    cin >> a >> b >> c >> N;
    int ans = 0;

    max_heap.push(a);
    max_heap.push(b);
    max_heap.push(c);

    min_heap.push(a);
    min_heap.push(b);
    min_heap.push(c);

    while (max_heap.top() < N) {
    	++ans;
        i64 A = min_heap.top();
        min_heap.pop();
        A = 2 * max_heap.top() - A;
        min_heap.push(A);
        max_heap.push(A);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    std::cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        solve();
    }

    return 0;
}