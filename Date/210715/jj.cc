#include <iostream>
typedef long long ll;
using namespace std;
const int MAXN = 510;
char mp[MAXN][MAXN];
int res[MAXN][MAXN];
int main(void)
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%s", mp[i] + 1);
		for (int j = 1; j <= n; ++j) {
			res[i][j] = mp[i][j] - '0';
		}
	}
	for (int i = 1; i <= n - 1; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			int temp = 0;  //方案数
			for (int k = i + 1; k <= j - 1; ++k) {
				temp += res[i][k] * res[k][j];
			}
			res[i][j] = (temp + 1) % 10 == res[i][j];
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			printf("%d", res[i][j]);
		}
		printf("\n");
	}
	return 0;
}