#include <bits/stdc++.h>
using namespace std;
#define LL long long
int main() {
    int T, n;
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);

        int t = n % 4;
        int kk = n / 4;

        if (t == 1) {
            printf("%d\n", 1 + 4 * kk);
            printf("1");
            for (int i = 1; i <= kk; ++i) {
                printf("1001");
            }
            printf("\n");
        } else if (t == 2) {
            printf("%d\n", 4 + 4 * kk);
            printf("0001");
            for (int i = 1; i <= kk; ++i) {
                printf("1001");
            }
            printf("\n");
        } else if (t == 3) {
            printf("%d\n", 2 + 4 * kk);
            printf("01");
            for (int i = 1; i <= kk; ++i) {
                printf("1001");
            }
            printf("\n");
        } else {
            printf("%d\n", 4 * kk);
            for (int i = 1; i <= kk; ++i) {
                printf("1001");
            }
            printf("\n");
        }
    }

    return 0;
}