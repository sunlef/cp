#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    priority_queue<int, vector<int>, greater<int>> heap;

    while (N--) {
        char op;
        cin >> op;
        if (op == 'I') {
            int x;
            cin >> x;
            if (int(heap.size()) < K) {
                heap.push(x);
            } else if (x > heap.top()) {
                heap.pop();
                heap.push(x);
            }
        } else {
            cout << heap.top() << '\n';
        }
    }

    return 0;
}