#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;

    auto calc = [](int state) -> int {
        deque<bool> st(10);
        for (int i = 0; i < 10; ++i) {
            if ((state >> i) & 1) {
                st[i] = true;
            }
        }
        int res = 0;
        for (int A = 1; A < 10; ++A) {
            if (!st[A]) {
                continue;
            }
            for (int B = 0; B < 10; ++B) {
                if (!st[B]) {
                    continue;
                }
                for (int C = 0; C < 10; ++C) {
                    if (!st[C]) {
                        continue;
                    }
                    for (int D = 1; D < 10; ++D) {
                        if (!st[D]) {
                            continue;
                        }
                        for (int E = 0; E < 10; ++E) {
                            if (!st[E]) {
                                continue;
                            }
                            int a = 100 * A + 10 * B + C;
                            int b = 10 * D + E;
                            int c1 = E * a, c2 = D * a, c3 = a * b;
                            string s1 = to_string(c1), s2 = to_string(c2), s3 = to_string(c3);
                            bool ok = true;
                            for (int i = 0; i < int(s1.size()); ++i) {
                                int x = s1[i] - '0';
                                if (!st[x]) {
                                    ok = false;
                                }
                            }
                            for (int i = 0; i < int(s2.size()); ++i) {
                                int x = s2[i] - '0';
                                if (!st[x]) {
                                    ok = false;
                                }
                            }
                            for (int i = 0; i < int(s3.size()); ++i) {
                                int x = s3[i] - '0';
                                if (!st[x]) {
                                    ok = false;
                                }
                            }
                            res += ok;
                        }
                    }
                }
            }
        }
        return res;
    };


    while (cin >> S) {
        int st = 0;

        deque<bool> visited(10);
        for_each(S.begin(), S.end(), [&](char ch) { visited[ch - '0'] = true; });

        for (int i = 0; i < 10; ++i) {
            if (visited[i]) {
                st |= (1 << i);
            }
        }

        cout << calc(st) << '\n';
    }


    return 0;
}