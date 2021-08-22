//记得乘1ll
//别让小数变成珂学计数
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>
#include<cmath>
#define SYNC ios::sync_with_stdio(0),cin.tie(0)
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define EPS 1e-6
#define endl '\n'
using namespace std;
const int MAXN = 114514;
int cnt[2000];
int s1, s2, s3;
void solve(){
	cin >> s1 >> s2 >> s3;
	for(int i = 1; i <= s1; ++i)
		for(int j = 1; j <= s2; ++j)
			for(int k = 1; k <= s3; ++k)
				++cnt[i+j+k];
	int max = -INF;
	int ans = 0;
	for(int i = 1; i <= s1+s2+s3; ++i)
		if(cnt[i] > max){
			max = cnt[i];
			ans = i;
		}
	cout << ans << endl;
}
int main(){
	SYNC;
	solve();
}
