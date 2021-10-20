/***

    Filename:   poj3140.cc
    Author:     CleanBlue
    Time:       2021-07-16 15:16:51 utc+8
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
#define PUB  push_back
#define DIV  cout << "\n==============================\n"

using namespace std;
typedef long long LoveLive;
typedef long double LD;
typedef unsigned long long ULL;
typedef LoveLive LL;
typedef pair<int, int> PII;
typedef pair<LoveLive, int> PLI;
typedef pair<LoveLive, LoveLive> PLL;
typedef vector<int> VI;
typedef vector<LoveLive> VLL;

//const double PI = acos(-1.0);
//const double EPS = 1e-6;
const int INF = 0x3f3f3f3f;
const int MAXN = 114514;

int N, M;
LL sum[SIZE];
LL total;
int caseidx;
LL ans;

int to[SIZE << 1], w[SIZE], head[SIZE], nxt[SIZE << 1];
int idx;
inline void add(int u, int v)
{
	to[++idx] = v;
	nxt[idx] = head[u];
	head[u] = idx;
}

LL DFS(int u, int fa)
{
	LL res = w[u];
	for (int e = head[u]; e; e = nxt[e]) {
		int v = to[e];
		if (v == fa)
			continue;
		res += DFS(v, u);
	}
	ans = min(ans, total - 2 * res > 0 ? total - 2 * res : 2 * res - total);
	return res;
}

void solve()
{
	total = 0;
	idx = 0;

	for (int i = 1; i <= N; ++i)
		head[i] = 0, sum[i] = 0, cin >> w[i], total += w[i];

	for (int i = 1; i <= M; ++i) {
		int u, v;
		cin >> u >> v;
		add(u, v), add(v, u);
	}

	ans = total;

	DFS(1, -1);

	cout << "Case " << ++caseidx << ": " << ans << ENDL;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> N >> M) {
		if (N == 0 && M == 0)
			break;
		solve();
	}

	return 0;
}