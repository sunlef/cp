#include <iostream>
#include <queue>
using namespace std;
const int N = 2e5 + 5;
struct Edge {
	int to, nex;
} edge[N << 1];
int head[N], tot;
inline void add(int from, int to)
{
	edge[++tot] = (Edge){to, head[from]}, head[from] = tot;
	edge[++tot] = (Edge){from, head[to]}, head[to] = tot;
}
int vis[N], dis[N], cnt[N], n, m;
queue<int> q;
int bfs()
{
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (cnt[x] == m)
			return x;
		for (int i = head[x]; i; i = edge[i].nex) {
			int y = edge[i].to;
			if (dis[y] == -1 || dis[y] == dis[x] + 1) {
				dis[y] = dis[x] + 1, cnt[y] += cnt[x];
				if (!vis[y])
					vis[y] = 1, q.push(y);
			}
		}
	}
	return -1;
}
int main()
{
	memset(dis, -1, sizeof dis);
	scanf("%d%d", &n, &m);
	for (int i = 1, x, y; i <= n - 1; ++i)
		scanf("%d%d", &x, &y), add(x, y);
	for (int i = 1, x; i <= m; ++i) {
		scanf("%d", &x), q.push(x), vis[x] = 1,
		                            dis[x] = 0, cnt[x] = 1;
	}
	int ans = bfs();
	if (ans != -1)
		printf("YES\n%d\n", ans);
	else
		puts("NO");
}
