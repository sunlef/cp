/*
    1   ADD(3)      0                                   3
    2   GET         1       3                           3 
    3   ADD(1)      1       1,                          3
    4   GET         2       1, 3                        3 
    5   ADD(-4)     2       -4, 1,                      3
    6   ADD(2)      2       -4, 1, 2,                   3
    7   ADD(8)      2       -4, 1, 2, 3,                8
    8   ADD(-1000)  2       -1000, -4, 1, 2, 3,         8
    9   GET         3       -1000, -4, 1, 2, 3, 8       1 
    10  GET         4       -1000, -4, 1, 2, 3, 8       2 
    11  ADD(2)      4       -1000, -4, 1, 2, 2, 3,      8
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N;
    cin >> M >> N;

    vector<int> A(M), B(N);
    for (int &i : A) {
        cin >> i;
    }
    for (int &i : B) {
        cin >> i;
    }

    priority_queue<int> greater_heap;
    priority_queue<int, vector<int>, greater<int>> less_heap;

    for (int i = 0, j = 0; i < N; ++i) {
        for (; j < B[i]; ++j) {
            less_heap.push(A[j]);
        }

        greater_heap.push(less_heap.top());
        less_heap.pop();

        while (!less_heap.empty() && less_heap.top() < greater_heap.top()) {
            int u = greater_heap.top(), v = less_heap.top();
            greater_heap.pop(), less_heap.pop();
            greater_heap.push(v), less_heap.push(u);
        }

        cout << greater_heap.top() << '\n';
    }

    return 0;
}