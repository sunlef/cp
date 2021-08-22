#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct MathTemplate{
    T power(T a, T k, T p) { //快速米
        T res = 1 % p;
        a = a % p;
        for(; k; k >>= 1, a = a * a % p)
            if(k&1)
                res = res * a % p;
        return res;
    }
    T times(T a, T b, T p) {
        T res = 0;
        for(; b; b >>= 1, a = 2 * a % p)
            if(b&1)
                res = (res + a) % p;
        return res;
    }
    T gcd(T __m, T __n) { //__gcd
        if (__m == 0) return __n; if (__n == 0) return __m;
        while (__n != 0) { T __t = __m % __n; __m = __n; __n = __t; }
        return __m;
    }
    T lcm(T __m, T __n) { //__lcm
      return (__m != 0 && __n != 0) ? (__m / gcd(__m, __n)) * __n : 0;
    }
    T getRevksm(T a, T p) { //欧拉逆天
        return power(a, p-2, p); 
    }
    T exgcd(T a, T b, T &x, T &y){
        if(a == 0 && b == 0) return -1;
        if(b == 0) { x = 1; y = 0; return a;}
        T d = exgcd(b, a%b, y, x);
        y -= a/b*x;
        return d;
    }
    T getRevexgcd(T a, T n) { //扩展欧几里得逆天
        T x, y;
        T d = exgcd(a, n, x, y);
        if(d == 1) return (x%n + n ) % n;
        else return -1;
    }
    void add(T &x,T v, T p) {x=(x+v)%p;if(x<0)x+=p;}
};
void solve(){
    using LL = long long;
    LL n, m, k, a, l;
    cin >> n >> m >> k >> a >> l;
    const int mod = 4933;

    LL ans = 1;
    MathTemplate<LL> M;
    for(int i = 0; i < k; ++i){
        int x, y, z;
        cin >> x >> y >> z;
        if(x == 0) continue;
        y = z - y;
        LL res = y * M.getRevksm(z,mod);
        ans = ans * res % mod;
    }

    ans = (ans + a) % mod;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned _TvT_ = 1;
    //cin >> _TvT_;
    for(unsigned i = 1; i <= _TvT_; ++i){
        solve();
    }

    return 0;
}