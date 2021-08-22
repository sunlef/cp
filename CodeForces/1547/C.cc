/***

    Filename:   C.cc
    Author:     CleanBlue
    Time:       2021-07-13 10:06:02 utc+8
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
const int MAXN = 114;

int k, n, m;
int a[SIZE], b[SIZE];

void solve()
{
	cin >> k >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= m; ++i)
		cin >> b[i];

	vector<int> ans;
	int posa = 1, posb = 1;
	for (int i = 1; i <= n + m; ++i) {
		if (posa <= n && a[posa] == 0) {
			ans.push_back(0);
			++posa;
			++k;
		}
		else if (posb <= m && b[posb] == 0) {
			ans.push_back(0);
			++posb;
			++k;
		}
		else if (posa <= n && posb <= m) {
			if (a[posa] < b[posb]) {
				if (a[posa] <= k) {
					ans.push_back(a[posa]);
					++posa;
				}
				else {
					cout << "-1" << ENDL;
					return;
				}
			}
			else {
				if (b[posb] <= k) {
					ans.push_back(b[posb]);
					++posb;
				}
				else {
					cout << -1 << ENDL;
					return;
				}
			}
		}
		else if (posa <= n) {
			if (a[posa] <= k) {
				ans.push_back(a[posa]);
				++posa;
			}
			else {
				cout << "-1" << ENDL;
				return;
			}
		}
		else if (posb <= m) {
			if (b[posb] <= k) {
				ans.push_back(b[posb]);
				++posb;
			}
			else {
				cout << -1 << ENDL;
				return;
			}
		}
		else {
			cout << "-1" << ENDL;
			return;
		}
	}

	for (auto i : ans)
		cout << i << " ";
	cout << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T = 1;
	cin >> T;
	while (T--)
		solve();

	return 0;
}