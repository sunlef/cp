#include<iostream>
#include<bitset>
#include<queue>
using namespace std;
const int N=3e4+10;
int net[N],head[N],ver[N],deg[N],tot,cnt,a[N],n,m;
bitset<N> f[N];
void add(int x,int y)//链式前向星加边
{
    ver[++tot]=y;
    net[tot]=head[x];
    head[x]=tot;
    deg[y]++;//deg为入度
}
void topsort(void)
{
    queue<int> q;
    for(int i=1;i<=n;i++)
        if (deg[i]==0)
            q.push(i);
    while(q.size())
    {
        int x=q.front();
        a[++cnt]=x;
        q.pop();
        for(int i=head[x];i;i=net[i])//链式前向星访问
        {
            int y=ver[i];
            deg[y]--;
            if (!deg[y])//入读为0,可以加入候选队列之中
                q.push(y);
        }
    }

}
void calc()
{
    for (int j = cnt; j; j--)
    {
        int x=a[j];
        f[x][x]=1;
        for (int i=head[x];i;i=net[i])
        {
            int y=ver[i];
            f[x]|=f[y];//求出集合
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
    }
    topsort();
    for(int i = 1; i <= cnt; ++i)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}
