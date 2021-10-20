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
const int MAXN = 1000500;
int n;
long long x;
bool is_prime[MAXN];
int prime[MAXN];
int primecnt;
void solve(){
	memset(is_prime, true, sizeof(is_prime));
	is_prime[1] = false;
	for(int i = 2; i <= 1000000; ++i){
		if(is_prime[i]){
			prime[++primecnt] = i;
			for(long long j = 1ll*i*i ; j <= 1000000; j += i)
				is_prime[j] = false;
		}
	}
	cin >> n;
	while(n--){
		cin >> x;
		int f = sqrt(x);
		int l = 1, r = primecnt+1;
		while(l <= r){
			int mid = l + (r-l >> 1);
			if(prime[mid] >= f)
				r = mid - 1;
			else
				l = mid + 1;
		}
		if(1ll*prime[l]*prime[l] == x)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
int main(){
	SYNC;
	solve();
}
