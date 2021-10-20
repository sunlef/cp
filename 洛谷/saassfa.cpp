//梳妆数组
int t[MAXN];
inline int lowbit(int x) { return x & -x; }
void treeBuild()
{
	for(int i = 1; i <= n; ++i) {
		t[i] += a[i];
		int j = i + lowbit(i);
		if(j <= n) t[j] += t[i];
	}
}
void treeAdd(int x, int pos)
{
	while(pos <= n) {
		t[pos] += x;
		pos += lowbit(pos);
	}
}
int treeQuery(int pos)
{
	int res = 0;
	while(pos >= 1) {
		res += t[pos];
		pos -= lowbit(pos);
	}
	return res;
}