//https://www.luogu.com.cn/problem/P1601

#include <bits/stdc++.h>
using namespace std;
// C = A + B, A >= 0, B >= 0
std::vector<int> add(std::vector<int> &A, std::vector<int> &B) {
    if (A.size() < B.size()) return add(B, A);
    std::vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); i++) {
        t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if (t) C.push_back(t);
    return C;
}

// C = A - B, 满足A >= B, A >= 0, B >= 0
std::vector<int> sub(std::vector<int> &A, std::vector<int> &B) {
    std::vector<int> C;
    for (int i = 0, t = 0; i < A.size(); i++) {
        t = A[i] - t;
        if (i < B.size()) t -= B[i];
        C.push_back((t + 10) % 10);
        if (t < 0)
            t = 1;
        else
            t = 0;
    }
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

// C = A * b, A >= 0, b >= 0
std::vector<int> mul(std::vector<int> &A, int b) {
    std::vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || t; i++) {
        if (i < A.size()) t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

// A / b = C ... r, A >= 0, b > 0
std::vector<int> div(std::vector<int> &A, int b, int &r) {
    std::vector<int> C;
    r = 0;
    for (int i = A.size() - 1; i >= 0; i--) {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string a, b;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    vector<int> v1, v2;
    for (auto &ch : a) {
        v1.emplace_back(ch - '0');
    }

    for (auto &ch : b) {
        v2.emplace_back(ch - '0');
    }

    vector<int> v3 = add(v1, v2);
    reverse(v3.begin(), v3.end());

    for (auto &x : v3) {
        cout << x;
    }
    cout << '\n';

    return 0;
}