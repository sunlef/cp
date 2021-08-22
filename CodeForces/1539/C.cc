/***

    Filename:   C.cc
    Author:     CleanBlue
    Time:       2021-07-14 16:26:45 utc+8
    Site:       cleanblue.moe

***/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define ENDL '\n'
#define SIZE MAXN
#define DIV  cout << "\n==============================\n"

using namespace std;
typedef long long LoveLive;
typedef long double LD;
typedef unsigned long long ULL;
typedef LoveLive LL;
typedef pair<int, int> PII;
typedef pair<LoveLive, int> PLI;
typedef pair<LoveLive, LoveLive> PLL;

//const double PI = acos(-1.0);
//const double EPS = 1e-6;
//const int INF = 0x3f3f3f3f;
const int MAXN = 214514;

LL n, k, x;
LL a[SIZE];

vector<LL> dis;

void solve()
{
	dis.clear();

	cin >> n >> k >> x;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	sort(a + 1, a + n + 1);

	int ans = 1;

	for (int i = 2; i <= n; ++i)
		if (a[i] - a[i - 1] > x) {
			++ans;
			dis.push_back(a[i] - a[i - 1]);
		}

	sort(dis.begin(), dis.end());

	for (auto i : dis) {
		LL l = (i - 1) / x;
		if (k >= l) {
			k -= l;
			--ans;
		}
		else
			break;
	}

	cout << ans << ENDL;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T = 1;
	//cin >> T;
	while (T--)
		solve();

	return 0;
}