#include <bits/stdc++.h>
using namespace std;

constexpr double EPS = 1e-12;

bool in(double l, double r, double x) {
    if (std::abs(x - l) > EPS && x < l) {
        return false;
    }
    if (std::abs(x - r) > EPS && x > r) {
        return false;
    }
    return true;
}


void solve() {
    double a, b, c;
    cin >> a >> b >> c;

    double X0, X1, Y0, Y1, Y2;
    cin >> X0 >> X1 >> Y0 >> Y1 >> Y2;

    auto f = [&](double x) -> double { return a * x * x + b * x + c; };

    double y = f(X0);
    if (std::abs(y - Y0) < EPS) {
        cout << "No\n";
        return;
    }

    y = f(X1);
    if (std::abs(y - Y0) < EPS) {
        cout << "No\n";
        return;
    }

    double Delta = b * b - 4 * a * (c - Y0);

    if (Delta <= 0) {
        cout << "No\n";
        return;
    }

    double rt = (-b - std::sqrt(Delta)) / (2 * a);
    double rtl = (-b + std::sqrt(Delta)) / (2 * a);

    if (in(X0, X1, rtl)) {
        cout << "No\n";
        return;
    }

    if (in(X0, X1, rt)) {
        cout << "Yes\n";
        return;
    } else if (in(Y0, Y2, y) && in(X1, X1 + (X1 - X0), rt)) {
        if (std::abs(X1 + (X1 - X0) - rt) < EPS) {
            cout << "No\n";
            return;
        }
        cout << "Yes\n";
        return;
    }
    cout << "No\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        solve();
    }

    return 0;
}