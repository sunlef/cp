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
          ~5"""""""""""^*^  ^'^^*T"%"%%5T^^"%55"""""""5"55T^"5""""""""""5"m,
=======================================CleanBlue.moe=======================================*/
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
#define SYNC                 \
	ios::sync_with_stdio(0); \
	cin.tie(0);
#define ENDL '\n'
#define SIZE MAXN
using namespace std;
typedef long long LoveLive;
//const double PI = acos(-1.0);
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;
typedef LoveLive LL;
const int MAXN = 114514;
struct Node {
	int x, y, z;
	bool operator<(const Node& B) const
	{
		if(x == B.x && y == B.y)
			return z < B.z;
		if(x == B.x)
			return y < B.y;
		return x < B.x;
	}
} a[9];
bool neq(const double& A, const double& B)
{
	return fabs(A - B) > EPS;
}
void solve()
{
	for(int i = 1; i <= 8; ++i)
		cin >> a[i].x >> a[i].y >> a[i].z;
	for(int i = 1; i <= 50000; ++i) {
		next_permutation(a + 1, a + 9);
		double t1 = sqrt((a[1].x - a[4].x) * (a[1].x - a[4].x) +
		                 (a[1].y - a[4].y) * (a[1].y - a[4].y) +
		                 (a[1].z - a[4].z) * (a[1].z - a[4].z));
		double t2 = sqrt((a[2].x - a[3].x) * (a[2].x - a[3].x) +
		                 (a[2].y - a[3].y) * (a[2].y - a[3].y) +
		                 (a[2].z - a[3].z) * (a[2].z - a[3].z));
		double t3 = sqrt((a[7].x - a[6].x) * (a[7].x - a[6].x) +
		                 (a[7].y - a[6].y) * (a[7].y - a[6].y) +
		                 (a[7].z - a[6].z) * (a[7].z - a[6].z));
		double t4 = sqrt((a[5].x - a[8].x) * (a[5].x - a[8].x) +
		                 (a[5].y - a[8].y) * (a[5].y - a[8].y) +
		                 (a[5].z - a[8].z) * (a[5].z - a[8].z));
		double t5 = sqrt((a[1].x - a[2].x) * (a[1].x - a[2].x) +
		                 (a[1].y - a[2].y) * (a[1].y - a[2].y) +
		                 (a[1].z - a[2].z) * (a[1].z - a[2].z));
		double t6 = sqrt((a[3].x - a[4].x) * (a[3].x - a[4].x) +
		                 (a[3].y - a[4].y) * (a[3].y - a[4].y) +
		                 (a[3].z - a[4].z) * (a[3].z - a[4].z));
		double t7 = sqrt((a[7].x - a[8].x) * (a[7].x - a[8].x) +
		                 (a[7].y - a[8].y) * (a[7].y - a[8].y) +
		                 (a[7].z - a[8].z) * (a[7].z - a[8].z));
		double t8 = sqrt((a[6].x - a[5].x) * (a[6].x - a[5].x) +
		                 (a[6].y - a[5].y) * (a[6].y - a[5].y) +
		                 (a[6].z - a[5].z) * (a[6].z - a[5].z));
		double t9 = sqrt((a[8].x - a[4].x) * (a[8].x - a[4].x) +
		                 (a[8].y - a[4].y) * (a[8].y - a[4].y) +
		                 (a[8].z - a[4].z) * (a[8].z - a[4].z));
		double t10 = sqrt((a[1].x - a[5].x) * (a[1].x - a[5].x) +
		                  (a[1].y - a[5].y) * (a[1].y - a[5].y) +
		                  (a[1].z - a[5].z) * (a[1].z - a[5].z));
		double t11 = sqrt((a[6].x - a[2].x) * (a[6].x - a[2].x) +
		                  (a[6].y - a[2].y) * (a[6].y - a[2].y) +
		                  (a[6].z - a[2].z) * (a[6].z - a[2].z));
		double t12 = sqrt((a[7].x - a[3].x) * (a[7].x - a[3].x) +
		                  (a[7].y - a[3].y) * (a[7].y - a[3].y) +
		                  (a[7].z - a[3].z) * (a[7].z - a[3].z));
		if(neq(t1, t2) || neq(t2, t3) || neq(t3, t4) || neq(t4, t5) ||
		   neq(t5, t6) || neq(t6, t7) || neq(t7, t8) || neq(t8, t9) ||
		   neq(t9, t10) || neq(t10, t11) || neq(t11, t12))
			continue;
		double b1 = sqrt((a[2].x - a[4].x) * (a[2].x - a[4].x) +
		                 (a[2].y - a[4].y) * (a[2].y - a[4].y) +
		                 (a[2].z - a[4].z) * (a[2].z - a[4].z));
		double b2 = sqrt((a[1].x - a[3].x) * (a[1].x - a[3].x) +
		                 (a[1].y - a[3].y) * (a[1].y - a[3].y) +
		                 (a[1].z - a[3].z) * (a[1].z - a[3].z));
		double b3 = sqrt((a[6].x - a[8].x) * (a[6].x - a[8].x) +
		                 (a[6].y - a[8].y) * (a[6].y - a[8].y) +
		                 (a[6].z - a[8].z) * (a[6].z - a[8].z));
		double b4 = sqrt((a[7].x - a[5].x) * (a[7].x - a[5].x) +
		                 (a[7].y - a[5].y) * (a[7].y - a[5].y) +
		                 (a[7].z - a[5].z) * (a[7].z - a[5].z));
		double b5 = sqrt((a[1].x - a[6].x) * (a[1].x - a[6].x) +
		                 (a[1].y - a[6].y) * (a[1].y - a[6].y) +
		                 (a[1].z - a[6].z) * (a[1].z - a[6].z));
		double b6 = sqrt((a[5].x - a[2].x) * (a[5].x - a[2].x) +
		                 (a[5].y - a[2].y) * (a[5].y - a[2].y) +
		                 (a[5].z - a[2].z) * (a[5].z - a[2].z));
		double b7 = sqrt((a[7].x - a[4].x) * (a[7].x - a[4].x) +
		                 (a[7].y - a[4].y) * (a[7].y - a[4].y) +
		                 (a[7].z - a[4].z) * (a[7].z - a[4].z));
		double b8 = sqrt((a[8].x - a[3].x) * (a[8].x - a[3].x) +
		                 (a[8].y - a[3].y) * (a[8].y - a[3].y) +
		                 (a[8].z - a[3].z) * (a[8].z - a[3].z));
		double b9 = sqrt((a[5].x - a[4].x) * (a[5].x - a[4].x) +
		                 (a[5].y - a[4].y) * (a[5].y - a[4].y) +
		                 (a[5].z - a[4].z) * (a[5].z - a[4].z));
		double b10 = sqrt((a[1].x - a[8].x) * (a[1].x - a[8].x) +
		                  (a[1].y - a[8].y) * (a[1].y - a[8].y) +
		                  (a[1].z - a[8].z) * (a[1].z - a[8].z));
		double b11 = sqrt((a[3].x - a[6].x) * (a[3].x - a[6].x) +
		                  (a[3].y - a[6].y) * (a[3].y - a[6].y) +
		                  (a[3].z - a[6].z) * (a[3].z - a[6].z));
		double b12 = sqrt((a[2].x - a[7].x) * (a[2].x - a[7].x) +
		                  (a[2].y - a[7].y) * (a[2].y - a[7].y) +
		                  (a[2].z - a[7].z) * (a[2].z - a[7].z));
		if(neq(b1, b2) || neq(b2, b3) || neq(b3, b4) || neq(b4, b5) ||
		   neq(b5, b6) || neq(b6, b7) || neq(b7, b8) || neq(b8, b9) ||
		   neq(b9, b10) || neq(b10, b11) || neq(b11, b12))
			continue;
		double c1 = sqrt((a[6].x - a[4].x) * (a[6].x - a[4].x) +
		                 (a[6].y - a[4].y) * (a[6].y - a[4].y) +
		                 (a[6].z - a[4].z) * (a[6].z - a[4].z));
		double c2 = sqrt((a[1].x - a[7].x) * (a[1].x - a[7].x) +
		                 (a[1].y - a[7].y) * (a[1].y - a[7].y) +
		                 (a[1].z - a[7].z) * (a[1].z - a[7].z));
		double c3 = sqrt((a[2].x - a[8].x) * (a[2].x - a[8].x) +
		                 (a[2].y - a[8].y) * (a[2].y - a[8].y) +
		                 (a[2].z - a[8].z) * (a[2].z - a[8].z));
		double c4 = sqrt((a[5].x - a[3].x) * (a[5].x - a[3].x) +
		                 (a[5].y - a[3].y) * (a[5].y - a[3].y) +
		                 (a[5].z - a[3].z) * (a[5].z - a[3].z));
		if(neq(c1, c2) || neq(c2, c3) || neq(c3, c4))
			continue;
		if(neq(t1 * t1 + b1 * b1, c1 * c1))
			continue;
		if(!neq(t1, 0) || !neq(b1, 0) || !neq(c1, 0))
			continue;
		cout << "YES" << ENDL;
		//cout << t1 << " " << b1 << " " << c1 << ENDL;
		return;
	}
	cout << "NO" << ENDL;
}
int main()
{
	SYNC;
	int T = 1;
	cin >> T;
	while(T--) {
		solve();
		//cout << ENDL;
	}
	return 0;
}