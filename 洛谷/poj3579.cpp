#define SYNC ios::sync_with_stdio(0),cin.tie(0)
#include<iostream>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
const int MAXN = 114514;
int N, C;
int a[MAXN];
bool check(int x){
	int cnt = 0;
	int j = 1;
	for(int i = 1; i <= N; ++i){
		while(j <= N && a[j] <= a[i] + x)
			++j;
		--j;
		cnt += j - i;
	}
	if(C % 2 == 0)
		return cnt < C >> 1;
	else
		return cnt <= C >> 1;
}
int main(){
	SYNC;
	while(cin >> N){
		C = N * (N-1) >> 1;
		for(int i = 1; i <= N; ++i)
			cin >> a[i];
		sort(a+1, a+N+1);
		int l = 0, r = INF;
		while(l <= r){
			int m = l + (r-l >> 1);
			if(check(m))
				l = m + 1;
			else
				r = m - 1;
		}
		cout << l << '\n';
	}
}
