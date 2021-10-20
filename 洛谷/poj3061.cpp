#include<iostream>
#include<cstdio>
#define SYNC ios::sync_with_stdio(0),cin.tie(0)
using namespace std;
const int MAXN = 114514;
int sum[MAXN], a;
int N, S;
bool check(int x){
	for(int i = x; i <= N; ++i)	//枚举看看有没有大于x的区间。
		if(sum[i] - sum[i-x] >= S)
			return true;
	return false;
}
int main(){
	SYNC;
	int T;
	cin >> T;
	while(T--){
		cin >> N >> S;
		for(int i = 1; i <= N; ++i){
			cin >> a;
			sum[i] = sum[i-1] + a;
		}
		if(S > sum[N]){
			cout << 0 << '\n';
			continue;
		}
		int l = 0, r = N;
		while(l <= r){
			int m = l + (r-l >> 1);
			if(check(m))
				r = m - 1;
			else
				l = m + 1;
		}
		cout << l << '\n';
	}
}
