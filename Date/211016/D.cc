#include <bits/stdc++.h>
using namespace std;

using ddd = tuple<double, double, double>;

double dist(const ddd& A, const ddd& B) {
    auto C1 = get<0>(A) - get<0>(B);
    auto C2 = get<1>(A) - get<1>(B);
    auto C3 = get<2>(A) - get<2>(B);
    return std::sqrt(C1 * C1 + C2 * C2 + C3 * C3);
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ddd> vec(n);

    for (auto& [x, y, z] : vec) {
        cin >> x >> y >> z;
    }

    double ans = INT_MAX;

    double t = 23333;

    ddd now(0, 0, 0);

    while (t > 1e-10) {
        ddd farthest = vec[0];

        double res = 0;
        for (auto& x : vec) {
            auto D = dist(x, now);
            if (D > res) {
                res = D;
                farthest = x;
            }
        }

        ans = min(ans, res);

        double x = get<0>(now), y = get<1>(now), z = get<2>(now);
        double fx = get<0>(farthest), fy = get<1>(farthest), fz = get<2>(farthest);

        x += (fx - x) * (t / 23333);
        y += (fy - y) * (t / 23333);
        z += (fz - z) * (t / 23333);

        now = {x, y, z};

        t *= 0.996;
    }

    cout << ans << '\n';

    return 0;
}