/***

    Filename:   C.cpp
    Author:     CleanBlue
    Time:       2021-06-07 19:18:13 utc+8
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
const int MAXN = 514514;

int n;
string s;
map<PII, int> mp;
int preD[SIZE];
int preK[SIZE];
int DP[SIZE];

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

void solve()
{
	mp.clear();
	cin >> n >> s;
	s = " " + s;
	for (int i = 1; i <= n; ++i)
		preD[i] = preD[i - 1] + (s[i] == 'D'),
		preK[i] = preK[i - 1] + (s[i] == 'K');
	for (int i = 1; i <= n; ++i) {
		if (preD[i] == 0 || preK[i] == 0)
			DP[i] = max(preD[i], preK[i]);
		else {
			int x = gcd(preD[i], preK[i]);
			int y = preD[i] / x;
			int z = preK[i] / x;
			DP[i] = DP[mp[{y, z}]] + 1;
			mp[{y, z}] = i;
		}
	}
	for (int i = 1; i <= n; ++i)
		cout << DP[i] << " \n"[i == n];
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