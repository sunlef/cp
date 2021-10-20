/***

    Filename:   c.cpp
    Author:     CleanBlue
    Time:       2021-06-06 20:12:39 utc+8
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

template <class T>
void _R(T& x)
{
	cin >> x;
}
void _R(int& x) { scanf("%d", &x); }
void _R(int64_t& x) { scanf("%lld", &x); }
void _R(double& x) { scanf("%lf", &x); }
void _R(char& x) { scanf(" %c", &x); }
void _R(char* x) { scanf("%s", x); }
void READ() {}
template <class T, class... U>
void READ(T& head, U&... tail)
{
	_R(head);
	READ(tail...);
}
template <class T>
void _W(const T& x)
{
	cout << x;
}
void _W(const int& x) { printf("%d", x); }
void _W(const int64_t& x) { printf("%lld", x); }
void _W(const double& x) { printf("%.16f", x); }
void _W(const char& x) { putchar(x); }
void _W(const char* x) { printf("%s", x); }
template <class T, class U>
void _W(const pair<T, U>& x)
{
	_W(x.first);
	putchar(' ');
	_W(x.second);
}
template <class T>
void _W(const vector<T>& x)
{
	for (auto i = x.begin(); i != x.end(); _W(*i++))
		if (i != x.cbegin())
			putchar(' ');
}
void WRITE() {}
template <class T, class... U>
void WRITE(const T& head, const U&... tail)
{
	_W(head);
	putchar(sizeof...(tail) ? ' ' : '\n');
	WRITE(tail...);
}

//const double PI = acos(-1.0);
//const double EPS = 1e-6;
//const int INF = 0x3f3f3f3f;
const int MAXN = 3001;

int N, M;
bool visted[SIZE][SIZE];
int head[SIZE], nxt[SIZE], to[SIZE];
int cnt;

inline void add(int u, int v)
{
	to[++cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt;
}

LL ans;
void dfs(int s, int u)
{
	for (int e = head[u]; e; e = nxt[e]) {
		int v = to[e];
		if (!visted[s][v]) {
			visted[s][v] = true;
			++ans;
			dfs(s, v);
		}
	}
}

void solve()
{
	READ(N, M);
	for (int i = 1; i <= N; ++i)
		add(i, i);
	while (M--) {
		int u, v;
		READ(u, v);
		add(u, v);
	}
	for (int i = 1; i <= N; ++i) {
		dfs(i, i);
	}
	WRITE(ans);
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