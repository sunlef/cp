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
//const double EPS = 1e-6;
const int INF = 0x3f3f3f3f;
typedef LoveLive LL;
const int MAXN = 114514;
int N;
int dfs(int x)
{
	if(x == 1)
		return 0;
	return 2 * dfs(x / 2) + 1;
}
void solve()
{
	cin >> N;
	cout << dfs(N) << endl;
}
int main()
{
	SYNC;
	int T;
	cin >> T;
	while(T--) {
		solve();
	}
	return 0;
}