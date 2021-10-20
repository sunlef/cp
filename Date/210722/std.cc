#include<iostream>
#include<vector>
#include<map>
#include<cmath>
typedef long long LL;
#define deb(x) std::clog << (#x) << " = " << (x) << '\n';
#define PII pair<int,int>
#define endl '\n'
#define pb(x) push_back(x)
#define cd complex<double>
const double PI = acos(-1.0);
using namespace std;
const int N = 15005;
vector<int> w[55], v[55];
int sz[55];
int dp[55][505];
int f[55][505][5];
void init() {
	for(int i = 0; i < 55; i++) {
		v[i].clear();
		w[i].clear();
	}
	memset(dp, -0x3f, sizeof dp);
	memset(f, -0x3f, sizeof f);
	memset(sz, 0, sizeof sz);
}
void solve() {
	init();
	int n, m;
	cin >> n;
	map<string, int> mp;
	int cnt = 0;
	string name;
	for(int i = 1; i <= n;i ++) {
		cin >> name;
        mp[name] = ++cnt;
	}
	cin >> m;
	int val, vol;
	while(m--) {
		cin >> name >> val >> vol;
		w[mp[name]].pb(val);
		v[mp[name]].pb(vol);
		sz[mp[name]]++;
	}
	int t, p;
	cin >> t >> p;
    //处理数据


	for(int i = 1; i <= n;i++) {// all subjects
		dp[i][0] = 0;
		for(int j = 0; j < sz[i]; j ++) {// i-th subj
			for(int k = t; k >= v[i][j]; k --) {
				dp[i][k] = min(100,max(dp[i][k], dp[i][k - v[i][j]] + w[i][j] ));
			}// 01 pack, calculate dp[i][j],(spend j days to study i-th class can get how much score)
		}
	}
	//求dp[i][j]

    f[0][0][0] = 0;
	//calculate f[i][j][p] : 花j天去复习前i门课，挂了不超过p科的最大分数
	for(int i = 1; i <= n;i ++) {//前n门
		for(int j = 0; j <= t; j ++) {//天数
			for(int k = 0; k <= p; k ++) {//挂科数
				for(int q = 0; q <= j; q ++) {//这一门学几天
                    if(dp[i][q] >= 60) {
						f[i][j][k] = max(f[i][j][k], f[i-1][j-q][k] + dp[i][q]);// 不挂
					} else {
						if(k)//不能从-1转移过来 
                            f[i][j][k] = max(f[i][j][k], f[i-1][j-q][k-1] + dp[i][q]);//挂
					}
                }
			}
		}
	}
    //求dp[i][j][k]


	int ans = -1;
	for(int i = 0; i <= p; i ++)
		ans = max(ans, f[n][t][i]);
	cout << ans << endl;
}
int main(){
    //srand(time(NULL) * time(NULL));
    ios::sync_with_stdio(false); cin.tie(0);
    int t ; cin >> t; while(t--)
    solve(); return 0;
}