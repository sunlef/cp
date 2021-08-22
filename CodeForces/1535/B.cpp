/***

    Filename:   B.cpp
    Author:     CleanBlue
    Time:       2021-06-04 22:47:21 utc+8
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
const int MAXN = 2014;

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}
bool visted[100006];
bool isprime[100006];
int prime[100000];
int cnt;
int n;
vector<int> v1, v2;
int b[SIZE];

void solve()
{
	v1.clear(), v2.clear();
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		if (x & 1)
			v1.push_back(x);
		else
			v2.push_back(x);
	}
	int count = 0;
	for (auto i : v2)
		b[++count] = i;
	for (auto i : v1)
		b[++count] = i;
	//	for (int i = 1; i <= n; ++i)
	//		cout << b[i] << " \n"[i == n];

	LL ans = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j) {
			//	cout << b[i] << " " << 2 * b[j] << " " << gcd(b[i], 2 * b[j]) << ENDL;
			if (gcd(b[i], 2 * b[j]) > 1)
				++ans;
		}
	cout << ans << ENDL;
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