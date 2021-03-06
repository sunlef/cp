/*                                     ,                             ,,,,,,
                                       ,,,@m########mp,,             qggggg@
                       ,s##@@###p,s########@q#qq############p,       @gggs##g#p
          ;        ,s@#################@####@##b################p    @ggs##gsq#b
           '*o,,p########bs########################################p 3gg#####b`
                    y#bq########q###########################@#########q@######n,
                  ;#s#########@##@#############@###@@@###########################p
               ,##q###############@@#gqqqq#@#####################################q
              sb$@bgggggg@##qqq######@######@############################q@###q@####p
            .#9@#s#################@########@#############################b^@###q3@###,
           ;#@@####@##@#####################@##############################b ^@###qp@##p
          $#@#####@#@@######################################################    7####q@#q
         @#@#####@#@########################################################b     7####@##
        @@########@##########################################################       7@####q
       @##################@##################################################         "@###b
     j@######################@###################@##########################          g"@##p
     j#######@####################################@@#########################p         j  @##q
    y###@########################################b@q@########################b         '   @###p
   @##b.@##############################################q@###################q        'b  @####p
  ,##b .^@########################################s#qq#########################'%o      'p  '@####q
 @#^   *j############@############b8################$##qq@#q#8#################         !    @#####q
z^    l j############################@###########bq@@#########################p        8    j###8##
     ~ j###########@###########@#bgpj##########bqs#@#@q@#@###8@###############~        b    j### 7#
    { y#######################gq@q#n @b8#######gq#c^@########pj@##############        $     @##b  7
     l@###@################b@##@b98p?b@b^8#####bq#c**j########^)@#############b       $     .###b
   .######################n#8#bcob  @@b @7@###q#c**o|@#b?8@#b.g@###########@#~      f      @##@b
   @#@#######b@######9@##@b@s#8qjb  jb  8ccc8c8c****c:c@##bzoc@###########b@b     ;"      @####b
  .#@#######b @#####bc$@##q@#c*c@pq##b  j#g88gswppp*****jv*^*j###########b b   ^^        @####b
  @#@####@#b  @#####pog@@@#qbo**b||    ^@co*n***cc7998bsnnppp@#@########b !~           ,######
 .##@##b@##@  8b@##*b**8@qg@b**@b9b@sgb|c*****************cc@###########~             @#####b
 @####b.@#b ",'bj@b*8p*c@@##***@#b*@c**********************j#q##########          ,s*^| .#b
 @###b l@#       @@p*@o*c?c****jb*o$**********************v@###########b
 @##b'b@j#      #b*@*8o*********b**@o******8@@qp*******jq@#############`
 @##   @"@     !p**8b***********@**@o******b@qg8@p***j#######@######@#b
 @#b   'p q     ^tp^************8c*jnpp***jp#*@9b*j##t@####bj######\@b
 '@b    !  \      '%p**************j@##g@## qpq@##gsq$@#b#@b@####b @#
  7#     ^          @o*************q, @bq@b)####bsqqq###p 'n###b  .b
   7p               'b***********j#b@$##q# @bqq##@qq#qq###q#"^    ^
    '*,     ,####mpp,s**********j@#p^@##@b @#q###qq@########p
           @##########o***yab7"@#@#######  ##@@#############b@#####np,psp,
          ~5"""""""""""^*^  ^'^^*t"%"%%5t^^"%55"""""""5"55t^"5""""""""""5"m,
=======================================cleanblue.moe=======================================*/
#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_map>
unsigned CASE_NUM;
using namespace std;

#define ENDL '\n'
#define MP  make_pair
#define LB  lower_bound
#define UB  upper_bound
#define EB  emplace_back
#define PQ  priority_queue
#define DIV cout << "=====\n"

#define AUTO(A, B)   for (auto A : (B))
#define MAXN(x)      const int SIZE = (x);
#define FORA(A,B, C) for (A = (B); A <= (C); ++A)
#define FOrA(A, B,C) for (A = (B); A <  (C); ++A)
#define DECA(A, B,C) for (A = (B); A >= (C); --A)
#define SOLVE_CASES  FORA(CASE_NUM, 1, _TvT_) solve()
#define FOR(A, B, C) for (auto A = (B); A <= (C); ++A)
#define FOr(A, B, C) for (auto A = (B); A <  (C); ++A)
#define DEC(A, B, C) for (auto A = (B); A >= (C); --A)

typedef long long                LoveLive;
typedef unsigned long long       ULL;
typedef LoveLive                 LL;
typedef pair<int, int>           PII;
typedef pair<LoveLive, int>      PLI;
typedef pair<LoveLive, LoveLive> PLL;
typedef set<int>                 SI;
typedef set<LoveLive>            SLL;
typedef map<int, int>            MII;
typedef map<LoveLive, int>       MLI;
typedef map<LoveLive, LoveLive>  MLL;
typedef map<char, int>           MCI;
typedef map<string, int>         MSI;
typedef queue<int>               QI;
typedef queue<LoveLive>          QLL;
typedef queue<PII>               QPII;
typedef priority_queue<int>      PQI;
typedef priority_queue<LoveLive> PQLL;
typedef priority_queue<PLI>      PQLI;
typedef vector<int>              VI;
typedef vector<LoveLive>         VLL;
typedef vector<double>           VD;
typedef vector<string>           VS;
typedef vector<PII>              VPII;

//const double EPS  = 1e-6;
//const double PI   = acos(-1.0);
//const int    INF  = 0x3f3f3f3f;
//const LL     LINF = 0x3f3f3f3f3f3f3f3fLL;
/*---VARIABLES---*/ MAXN(114514) /*---VARIABLES---*/

/*----------- SOLVE CASES -----------*/
void solve(){

}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    unsigned _TvT_ = 1;
    //cin >> _TvT_;
    SOLVE_CASES;
    return 0;
}