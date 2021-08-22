#include<iostream>
#define SYNC ios::sync_with_stdio(0),cin.tie(0)
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
const int MAXN = 114514;
int N, C;
int a[MAXN];
bool check(int x){
	int cnt = 1;	//cnt是当前放了几头牛。
					//我们已经把第一头牛放到最左边了。
					//所以cnt初值为1；
	int last = a[1];//last是上一个放牛的牛棚。
	for(int i = 2; i <= N; ++i)	//枚举之后的牛棚。
		if(a[i] - last > x){	//如果该牛棚与last的距离超过该二分答案，就可以再放一头了。
			++cnt;
			last = a[i];
		}
	return cnt >= C;
}
int main(){
	SYNC;
	cin >> N >> C;
	for(int i = 1; i <= N; ++i)
		cin >> a[i];
	sort(a+1, a+N+1);
	int l = 0, r = INF;
	while(l <= r){	//二分答案，距离。
		int m = l + (r-l >> 1);
		if(check(m))
			l = m + 1;
		else
			r = m - 1;
	}
	cout << l << endl;
}
