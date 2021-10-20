/***

    Filename:   B.cpp
    Author:     CleanBlue
    Time:       2021-06-06 23:17:08 utc+8
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
const int MAXN = 114514;

string s, ss;
int n;
map<string, bool> mp;

void solve()
{
	mp.clear();
	cin >> n;
	cin >> ss;
	for (int i = 0; i < n; ++i) {
		mp[ss.substr(i, 1)] = true;
		if (i + 1 < n)
			mp[ss.substr(i, 2)] = true;
		if (i + 2 < n)
			mp[ss.substr(i, 3)] = true;
		if (i + 3 < n)
			mp[ss.substr(i, 4)] = true;
	}
	//for (auto [i, j] : mp)
	//	cout << i << " "<< j << endl;
	for (char i = 'a'; i <= 'z'; ++i) {
		s = "";
		s = s + i;
		if (!mp[s]) {
			cout << s << endl;
			return;
		}
	}
	for (char i = 'a'; i <= 'z'; ++i)
		for (char j = 'a'; j <= 'z'; ++j) {
			s = "";
			s = s + i + j;
			if (!mp[s]) {
				cout << s << endl;
				return;
			}
		}
	for (char i = 'a'; i <= 'z'; ++i)
		for (char j = 'a'; j <= 'z'; ++j)
			for (char k = 'a'; k <= 'z'; ++k) {
				s = "";
				s = s + i + j + k;
				if (!mp[s]) {
					cout << s << endl;
					return;
				}
			}
	for (char i = 'a'; i <= 'z'; ++i)
		for (char j = 'a'; j <= 'z'; ++j)
			for (char k = 'a'; k <= 'z'; ++k)
				for (char l = 'a'; l <= 'z'; ++l) {
					s = "";
					s = s + i + j + k + l;
					if (!mp[s]) {
						cout << s << endl;
						return;
					}
				}
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