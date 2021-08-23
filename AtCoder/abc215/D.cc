#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    int CNT = M;
    vector<int> ans(M + 1, 1);

    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        vector<int> primes;
        for (int i = 2; i <= sqrt(a); ++i) {
            while (a % i == 0) {
                a /= i;
                primes.emplace_back(i);
            }
        }
        if (a != 1) {
            primes.emplace_back(a);
        }

        for (auto prime : primes) {
            if (prime <= M && ans[prime]) {
                for (int k = 1; (long long)k * prime <= M; ++k) {
                    if (ans[k * prime]) {
                        --CNT;
                        ans[k * prime] = 0;
                    }
                }
            }
        }
    }

    cout << CNT << '\n';
    for (int i = 1; i <= M; ++i) {
        if (ans[i]) {
            cout << i << '\n';
        }
    }

    return 0;
}