/***

    Filename:   dabiao.cpp
    Author:     CleanBlue
    Time:       2021-06-06 22:53:12 utc+8
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

void solve()
{
	int cnt = 0;
	string s;
	for (char i = 'a'; i <= 'z'; ++i) {
		s = "";
		s = s + i;
		cout << "d[" << ++cnt << "]"
		     << " = "
		     << "\"" << s
		     << "\"" << ';' << ENDL;
	}
	for (char i = 'a'; i <= 'z'; ++i) {
		for (char j = 'a'; j <= 'z'; ++j) {
			s = "";
			s = s + i + j;
			cout << "d[" << ++cnt << "]"
			     << " = "
			     << "\"" << s
			     << "\"" << ';' << ENDL;
		}
	}
	for (char i = 'a'; i <= 'z'; ++i) {
		for (char j = 'a'; j <= 'z'; ++j) {
			for (char k = 'a'; k <= 'z'; ++k) {
				s = "";
				s = s + i + j + k;
				cout << "d[" << ++cnt << "]"
				     << " = "
				     << "\"" << s
				     << "\"" << ';' << ENDL;
			}
		}
	}
	/*for (char i = 'a'; i <= 'z'; ++i) {
		for (char j = 'a'; j <= 'z'; ++j) {
			for (char k = 'a'; k <= 'z'; ++k)
				for (char l = 'a'; l <= 'z'; ++l) {
					s = "";
					s = s + i + j + k + l;
					cout << "d[" << ++cnt << "]"
					     << " = "
					     << "\"" << s
					     << "\"" << ';' << ENDL;
				}
		}
	}*/
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