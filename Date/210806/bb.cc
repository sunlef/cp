#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 5e3+5;
ll f[2][maxn][2] , a[maxn];
bool vis[2][maxn][2];
void solve(){
	int n , m , last;
	scanf("%d%d" , &n , &m);
	ll sum = 0 , cnt = 0;
	for(int i = 1;i <= n;i++)scanf("%lld" , a+i) , cnt += a[i];
	memset(f , 0xf3 , sizeof f);
	vis[0][0][0] = 1 , f[0][0][0] = 0;
	for(int i = 1;i <= n;i++){
		last = (i - 1)%2;
		for(int j = 0;j <= m;j++){
			if(vis[last][j][0]){
                cout << i << " " << j << endl;
				f[i%2][j+1][1] = max(f[last][j][0] + a[i] , f[i%2][j+1][1]);
				f[i%2][j][0] = max(f[last][j][0] , f[i%2][j][0]);
				vis[i%2][j+1][1] = vis[i%2][j][0] = 1;
			}
			if(vis[last][j][1]){
				f[i%2][j+1][1] = max(f[last][j][1] + a[i] , f[i%2][j+1][1]);
				f[i%2][j][1] = max(f[last][j][1] + a[i] , f[i%2][j][1]);
				f[i%2][j][0] = max(f[last][j][1] , f[i%2][j][0]);
				vis[i%2][j][0] = vis[i%2][j][1] = vis[i%2][j+1][1] = 1;
			}
		}
		for(int j = 0;j <= m;j++){
			f[last][j][1] = f[last][j][0] = 0xf300000000000000;
			vis[last][j][0] = vis[last][j][1] = 0;
		}
	}
	sum = max(f[n%2][m][0] , f[n%2][m][1]);
	
	memset(f , 0x3f , sizeof f);
	memset(vis , 0 , sizeof vis);
	f[1][0][0] = 0 , vis[1][0][0] = 1;
	for(int i = 2;i < n;i++){
		last = (i - 1)%2;
		for(int j = 0;j <= m;j++){
			if(vis[last][j][0]){
				f[i%2][j+1][1] = min(f[last][j][0] + a[i] , f[i%2][j+1][1]);
                DEB(f[i%2][j+1][1]);
				f[i%2][j][0] = min(f[last][j][0] , f[i%2][j][0]);
                DEB(f[i%2][j][0]);
	
				vis[i%2][j+1][1] = vis[i%2][j][0] = 1;
			}
			if(vis[last][j][1]){
				f[i%2][j][1] = min(f[last][j][1] + a[i] , f[i%2][j][1]);
                DEB(f[i%2][j][1]);
				f[i%2][j][0] = min(f[last][j][1] , f[i%2][j][0]);
                DEB(f[i%2][j][0]);
	
				vis[i%2][j][0] = vis[i%2][j][1] = 1;
			}
		}
		for(int j = 0;j <= m;j++){
			f[last][j][1] = f[last][j][0] = 0x3f00000000000000;
			vis[last][j][0] = vis[last][j][1] = 0;
		}
	}
	sum = max(cnt - min(f[(n-1)%2][m][0] , f[(n-1)%2][m][1]) , sum);
	printf("%lld\n",sum);
	return;
}
int main(){
	solve();
	return 0;
}