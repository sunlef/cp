#include<iostream>
#include<cmath>
typedef long long LL;
typedef unsigned long long ULL;
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define pb(x) emplace_back(x)
#define deb(x) std::clog << (#x) << " = " << (x) << '\n';
#define PII pair<int, int>
#define endl '\n'
#define cd complex<double>
const double PI = acos(-1.0);
const int N = 2e5 + 10;
using namespace std;
LL cnt;
bool vis[20000010];
LL primes[20000010];
#define RD(x) fixed << setprecision(x)
bool isprime(LL x)
{
    if(x <= 1)
        return false;
    if(x == 2)
        return true;
    return (!vis[x]);
}
void solve()
{
    LL n; cin >> n;
    if(n == 0) {
        cout << 3 << endl;
        return;
    }
    LL res = 0;
    if(n < 0) {
        res = (LL)(-2 * n + 1);
        n = -n + 1;
        if(isprime(n))
            res++;
        else if(isprime(2 * n + 1))
            res += 2;
        else
            res = -1;
    }
    else {
        if(isprime(n))
            res += 1;
        else if(isprime(2 * n - 1) || isprime(2 * n + 1))
            res += 2;
        else
            res = -1;
    }
    cout << res << endl;
}
int main()
{
    //srand(time(NULL) * time(NULL));
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(vis, 0, sizeof vis);
    memset(primes, 0, sizeof primes);
    for(LL i = 2; i <= 20000007; i++) {
        if(!vis[i]) {
            primes[cnt++] = i;
        }
        for(LL j = 0; primes[j] <= 20000007 / i; j++) {
            vis[primes[j] * i] = true;
            if(i % primes[j] == 0)
                break;  //已经被之前的数筛掉过了
        }
    }
    LL t ; cin >> t; while(t--)
    solve();
    return 0;
}