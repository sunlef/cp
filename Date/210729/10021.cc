#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<sstream>
#include<cstring>
#include<bitset>
#include<cstdio>
#include<string>
#include<deque>
#include<stack>
#include<cmath>
#include<queue>
#include<set>
#include<map>
const int mod = 1e9+7;
const int MOD = 1e9+9;
using namespace std;
typedef long long LL;
const int maxn = 4e3+10;

int n;

struct node
{
    int to, w, next;
}e[4010];
int head[4010];

int m,cnt,k,N;
int c[2005];

int fa[maxn][20]; //表示节点i往上跳2^j次后的节点  注意j的取值范围
int d[maxn];  //当前节点所在的深度
int dis[maxn]; //到根节点的距离

LL a[2005][2005];
LL pre[2005];
int p;

LL func(LL i,LL x,LL md) {
    LL res = 0;
    LL tt = 1;
    for(LL j=1;j<=n;j++) {
        res = (res%md + a[i][j]%md*tt%md)%md;
        tt=(tt*x)%md;
    }
    return res%md;
}

void dfss(int u, int fa, LL faw){
    pre[u] = c[u] + faw;
     for(int i=head[u]; i ;i=e[i].next){
        int v = e[i].to;
        if(v == fa) continue;
        dfss(v,u,pre[u]);
    }
}
void add(int u,int v, int w)
{
    cnt++;
    e[cnt].w = w;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}
void init()  //初始化
{
    cnt = 0;
    N = (int)(log(1.0*n)/log(2))+1;
    memset(dis,0,sizeof(dis));
    memset(d,0,sizeof(d));
    memset(head,0,sizeof(head));
    memset(fa,0,sizeof(fa));
}
void dfs(int u,int f)
{
    for(int i=1;i<=N;i++)
        fa[u][i] = fa[fa[u][i-1]][i-1];  //i的第2^j祖先就是i的第2^(j-1)祖先的第2^(j-1)祖先
 
    for(int i=head[u]; i ;i=e[i].next)   //每一个与u相连的节点i
    {
        int v = e[i].to;
        if(v==f)
            continue;
        d[v] = d[u]+1;    //更新深度
        dis[v] = dis[u]+e[i].w;  //更新到根节点的距离
        fa[v][0] = u;
        dfs(v,u);
    }
}//深搜出各点的深度，存在d中
/*void bz()
{
    for(int j=1;j<=19;j++)
        for(int i=1;i<=n;i++)
            fa[i][j] = fa[fa[i][j-1]][j-1];
}*/
int lca(int u,int v)
{
    if(d[u]<d[v])
    swap(u,v);   //保证深度大的点为u，方便操作
    int dc=d[u]-d[v];   //计算深度差
    int i;
    for(i=0;i<=N;i++)  //值得注意的是，这里需要从零枚举
    {                    //此循环用于提到深度相同
        if((1<<i)& dc)
            u=fa[u][i];
    }
    if(u==v)   //如果深度一样时，两个点相同，直接返回
        return u;
    for(i=N;i>=0;i--)  //如果从小到大的话就有可能无法提到正确位置
    {
        if(fa[u][i]!=fa[v][i])//跳2^j步，如果不一样，就跳，否则不跳 如果相等有可能都为0 即超过根节点
        {//在同一高度了,他们一起向上跳,跳他们不相同节点，当全都跳完之后fa[u][0]就是lca
            u=fa[u][i];
            v=fa[v][i];
        }
    }
    u=fa[u][0]; //上述过程做完，两点都在LCA下一层，所以走一步即可
    return u;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int T;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        for(int i=2;i<=n;i++) {
            cin>> p;
            add(i,p,1);
            add(p,i,1);
        }
        for(int i=1;i<=n;i++) {
            cin>>c[i];
        }
        dfss(1,-1,0);

        d[1]=1;
        dfs(1,0);
        
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                int tt = lca(i,j);
                a[i][j]=pre[i]+pre[j]-2*pre[tt]+c[tt];
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        
		for(int i = 1; i <= 6; i++) {
			cout << func(i, 19560929, mod) << " " << func(i, 19560929, MOD) << endl;
		}
	}
    return 0;
}