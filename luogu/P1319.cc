#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::string str;

    int x;
    bool flag = true;
    while (std::cin >> x) {
        if (flag) {
            for (int i = 0; i < x; ++i) {
                str.push_back('0');
            }
        } else {
            for (int i = 0; i < x; ++i) {
                str.push_back('1');
            }
        }
        flag = !flag;
    }

    std::vector<std::string> vs;
    for (int i = 0; i + N - 1 < int(str.size()); i += N) {
        vs.push_back(str.substr(i, N));
    }

    for (auto &x : vs) {
        std::cout << x << '\n';
    }
    return 0;
}