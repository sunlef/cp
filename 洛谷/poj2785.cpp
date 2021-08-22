#define SYNC ios::sync_with_stdio(0),cin.tie(0)
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 4514;
int ab[MAXN*MAXN], cd[MAXN*MAXN];	//大的数组放在外面定义，不然容易RE
int n, ans;
int a[MAXN], b[MAXN], c[MAXN], d[MAXN];
int main(){
	SYNC;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	int cnt = 0;
	for(int i = 1; i <= n; ++i)	//处理(a+b) 和 (c+d)
		for(int j = 1; j <= n; ++j){
			ab[++cnt] = a[i] + b[j];
			cd[cnt] = c[i] + d[j];
		}
	sort(cd + 1, cd + cnt + 1);
	for(int i = 1; i <= cnt; ++i){	//对每一组(a+b)枚举
		int r = upper_bound(cd+1, cd+cnt+1, -ab[i]) - cd;
		int l = lower_bound(cd+1, cd+cnt+1, -ab[i]) - cd;
		ans += r - l;	//r-l 就是 upper_bound - lower_bound 就是cd中值为-ab[i] 的元素的数量
	}
	cout << ans << endl;
}
