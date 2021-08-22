#include <iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
typedef long long LL;
typedef unsigned long long ULL;
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define pb(x) emplace_back(x)
#define deb(x) std::clog << (#x) << " = " << (x) << '\n';
#define PII pair<int, int>
#define endl '\n'
#define cd complex<double>
const double PI = acos(-1.0);
using namespace std;
LL cnt;
bool vis[30000010];
LL primes[30000010];
#define RD(x) fixed << setprecision(x)
bool ok(LL x)
{
	if(x <= 1)
		return false;
	if(x == 2)
		return true;
	return (vis[x]==0);
}
LL solve(LL n)
{
    
	if(n == 0) {
		return 3;
	}
	LL res = 0;
	if(n>0) {
        if(ok(n)) res=1;
        else if(ok(2*n+1)||ok(2*n-1))res=2;
        else if(ok(n+1))res=2*n+2;
        else if(ok(2*n+3))res=2*n+3;
        else res=-1;
    } else if(n<0) {
        if(ok(-n+1))res=-2*n+2;
        else if(ok(-2*n+3))res=-2*n+3;
        else if(ok(-n+2))res=-2*n+4;
        else if(ok(-2*n+5))res=-2*n+5;
        else res=-1;
    }
	if(res == -1){
        if(n < 0) return solve(n-1);
        else return solve(n+1);
    }
    return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    memset(vis, 0, sizeof vis);
	memset(primes, 0, sizeof primes);
	for(LL i = 2; i <= 30000007; i++) {
		if(!vis[i]) {
			primes[cnt++] = i;
		}
		for(LL j = 0; primes[j] <= 30000007 / i; j++) {
			vis[primes[j] * i] = true;
			if(i % primes[j] == 0)
				break;  //已经被之前的数筛掉过了
		}
	}
	LL t ; cin >> t; while(t--)
	{
        LL x;
        cin >> x;
        cout << solve(x) << '\n';
    }
	return 0;
}