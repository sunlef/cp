#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (scanf("%d", &n)) {
        if (n == 0) {
            break;
        }
        int cnt = 0;
        char ch;
        int h1, m1, s1, h2, m2, s2;
        int t, tt, d;
        for (int i = 0; i < n; ++i) {
            scanf(" %c:%d:%d:%d:%d:%d:%d", &ch, &h1, &m1, &s1, &h2, &m2, &s2);
            t = s1 + 60 * m1 + 60 * 60 * h1;
            tt = s2 + 60 * m2 + 60 * 60 * h2;
            if (tt < t) {
                tt = 60 * 60 * 24;
            }
            t = max(t, 60 * 60 * 8 + 60 * 30);
            d = tt - t;
            if (ch == 'D') {
                int CUTTOFF = 60 * 60 * 9 + 60 * 30;
                int LEN = 60 * 60 * 8;
                if (t > CUTTOFF || d < LEN) {
                    ++cnt;
                }

            } else {
                int CUTTOFF = 60 * 60 * 12 + 60 * 30;
                int LEN = 60 * 60 * 9;
                if (t > CUTTOFF || d < LEN) {
                    ++cnt;
                }
            }
        }
        if (cnt) {
            if (cnt <= 3) {
                printf("%d Point(s) Deducted\n", cnt);
            } else {
                printf("Issue Show Cause Letter\n");
            }
        } else {
            printf("All OK\n");
        }
    }

    return 0;
}