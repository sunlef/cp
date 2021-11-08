#include <bits/stdc++.h>
using namespace std;
using u64 = uint64_t;

struct Node {
    int x, y;
};

struct Line {
    int dx, dy;
    u64 hash(const Node& lhs, const Node& rhs) {
        int t = gcd(dx, dy);
        dx /= t;
        dy /= t;
        return 114514 + 1919810 * dx + 2333333 * dy;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;



    return 0;
}