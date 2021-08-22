/*                                     ,                             ,,,,,,
                                       ,,,@m########mp,,             QGGGGG@
                       ,s##@@###p,s########@Q#QQ############p,       @GGGS##G#p
          ;        ,s@#################@####@##b################p    @GGS##GSQ#b
           '*o,,p########bS########################################p 3GG#####b`
                    y#bQ########Q###########################@#########Q@######N,
                  ;#S#########@##@#############@###@@@###########################p
               ,##Q###############@@#GQQQQ#@#####################################Q
              sb$@bGGGGGG@##QQQ######@######@############################Q@###Q@####p
            .#9@#S#################@########@#############################b^@###Q3@###,
           ;#@@####@##@#####################@##############################b ^@###Qp@##p
          $#@#####@#@@######################################################    7####Q@#Q
         @#@#####@#@########################################################b     7####@##
        @@########@##########################################################       7@####Q
       @##################@##################################################         "@###b
     j@######################@###################@##########################          G"@##p
     j#######@####################################@@#########################p         j  @##Q
    y###@########################################b@Q@########################b         '   @###p
   @##b.@##############################################Q@###################Q        'b  @####p
  ,##b .^@########################################S#QQ#########################'%o      'p  '@####Q
 @#^   *j############@############b8################$##QQ@#Q#8#################         !    @#####Q
z^    l j############################@###########bQ@@#########################p        8    j###8##
     ~ j###########@###########@#bGpj##########bQS#@#@Q@#@###8@###############~        b    j### 7#
    { y#######################GQ@Q#N @b8#######GQ#C^@########pj@##############        $     @##b  7
     L@###@################b@##@b98p?b@b^8#####bQ#C**j########^)@#############b       $     .###b
   .######################N#8#bCob  @@b @7@###Q#C**o|@#b?8@#b.G@###########@#~      f      @##@b
   @#@#######b@######9@##@b@S#8Qjb  jb  8CCC8C8C****C:C@##bzoC@###########b@b     ;"      @####b
  .#@#######b @#####bC$@##Q@#C*C@pQ##b  j#G88GSWppp*****jv*^*j###########b b   ^^        @####b
  @#@####@#b  @#####poG@@@#Qbo**b||    ^@Co*N***CC7998bSNNppp@#@########b !~           ,######
 .##@##b@##@  8b@##*b**8@QG@b**@b9b@sGb|c*****************CC@###########~             @#####b
 @####b.@#b ",'bj@b*8p*C@@##***@#b*@C**********************j#Q##########          ,s*^| .#b
 @###b l@#       @@p*@o*C?C****jb*o$**********************v@###########b
 @##b'b@j#      #b*@*8o*********b**@o******8@@Qp*******jQ@#############`
 @##   @"@     !p**8b***********@**@o******b@QG8@p***j#######@######@#b
 @#b   'p Q     ^Tp^************8c*jNpp***jp#*@9b*j##T@####bj######\@b
 '@b    !  \      '%p**************j@##G@## QpQ@##GSQ$@#b#@b@####b @#
  7#     ^          @o*************Q, @bQ@b)####bSQQQ###p 'N###b  .b
   7p               'b***********j#b@$##Q# @bQQ##@QQ#QQ###Q#"^    ^
    '*,     ,####mpp,S**********j@#p^@##@b @#Q###QQ@########p
           @##########o***yAb7"@#@#######  ##@@#############b@#####Np,psp,
          ~5"""""""""""^*^  ^'^^*T"%"%%5T^^"%55"""""""5"55T^"5""""""""""5"m,                      */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#define SYNC ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
using namespace std;
typedef long long LL;
//const double PI = acos(-1.0);
//const double EPS = 1e-6;
const int INF = 0x3f3f3f3f;
const int MAXN = 101514;
LL gcd(LL a, LL b) {
	if(b == 0)
		return a;
	return gcd(b, a % b);
}
#define __qReadType LL
inline __qReadType read() {
	__qReadType x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-')
			f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = 10 * x + ch - '0';
		ch = getchar();
	}
	return f * x;
}
LL n, a[MAXN];
struct Node {
	LL i, j, x, y;
} u;
vector<Node> ans;
void solve() {
	ans.clear();
	n = read();
	for(int i = 1; i <= n; ++i)
		a[i] = read();
	if(n == 1) {
		cout << 0 << endl;
		return;
	}
	for(int i = 2; i < n; ++i) {
		if(gcd(a[i], a[i - 1]) > 1) {
			int minn = min(a[i], a[n]);
			if(minn == a[i]) {
				a[n] = a[i];
				while(gcd(a[i], a[i - 1]) != 1)
					++a[i];
			} else {
				while(gcd(a[i], a[i - 1]) != 1)
					++a[i];
			}
			u.i = i, u.j = n, u.x = a[i], u.y = a[n];
			ans.push_back(u);
		}
	}
	if(gcd(a[n], a[n - 1]) != 1) {
		if(a[n] > a[n - 1]) {
			while(gcd(a[n], a[n - 1]) != 1)
				++a[n];
		} else {
			if(n > 2) {
				while(gcd(a[n], a[n - 1]) != 1 || gcd(a[n - 2], a[n - 1]) != 1)
					++a[n - 1];
			} else {
				while(gcd(a[n], a[n - 1]) != 1)
					++a[n - 1];
			}
		}
		u.i = n - 1, u.j = n, u.x = a[n - 1], u.y = a[n];
		ans.push_back(u);
	}

	cout << ans.size() << endl;
	for(auto i : ans)
		cout << i.i << " " << i.j << " " << i.x << " " << i.y << endl;
}
int main() {
	SYNC;
	int t = read();
	while(t--)
		solve();
	return 0;
}