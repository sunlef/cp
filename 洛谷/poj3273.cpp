#define SYNC ios::sync_with_stdio(0),cin.tie(0)
#define INF 0x3f3f3f3f
#include<iostream>
using namespace std;
const int MAXN = 114514;
int N, M;
int a[MAXN];
bool check(int x){
	int slash = 0, now = 0;	//slash是挡板的数量，now是当前阶段的支出总量。
	for(int i = 1; i <= N; ++i){
		if(now + a[i] > x){	//如果当前支出总量超过了枚举的答案，就要加一块挡板了。
			++slash;
			now = a[i];
		}
		else
			now += a[i];
	}
	return slash <= M - 1;	//分成M分要用M-1块挡板。
}
int main(){
	SYNC;
	cin >> N >> M;
	int maxx = -INF;
	for(int i = 1; i <= N; ++i){
		cin >> a[i];
		maxx = max(maxx, a[i]);
	}
	int l = maxx, r = INF;	//l要设为元素的最大值。
	while(l <= r){	//二分答案
		int m = l + (r-l >> 1);
		if(check(m))
			r = m - 1;
		else
			l = m + 1;
	}
	cout << l << endl;
}
