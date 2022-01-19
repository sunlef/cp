#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;

    vector<int> A(N);
    for (int &i : A) {
        cin >> i;
    }

    nth_element(A.begin(), A.begin() + N / 2, A.end());

    cout << A[N / 2] << '\n';
    return 0;
}