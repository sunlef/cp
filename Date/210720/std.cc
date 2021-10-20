#include<iostream>
using namespace std;
const int N = 1e3 + 5;
int n, m, a[N][N], ax, ay;
int up[N][N], dwn[N][N], l[N][N], r[N][N];
int dl[N], dr[N];
char s[N][N], t[N][N];
void work(int u, int d, int l, int r)
{
    if(u>d || l>r) return;
    int pre = u - 1;
    for(int i=u; i<=d; i++)
    {
        bool fl = 0;
        for(int j=l; j<=r; j++) if(isalpha(s[i][j])) fl = 1;
        if(!fl) continue;
        int p = l - 1;
        for(int j=l; j<=r; j++)
            if(isalpha(s[i][j]))
            {
                for(int k=p+1; k<j; k++) t[i][k] = tolower(s[i][j]);
                t[i][j] = s[i][j];
                p = j;
            }
        for(int j=p+1; j<=r; j++) t[i][j] = tolower(t[i][p]);
        for(int j=pre+1; j<i; j++)
            for(int k=l; k<=r; k++) t[j][k] = tolower(t[i][k]);
        pre = i;
    }
    for(int i=pre+1; i<=d; i++)
        for(int j=l; j<=r; j++) t[i][j] = tolower(t[pre][j]);
}
void gao()
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(a[i][j]) l[i][j] = r[i][j] = j;
    for(int i=1; i<=n; i++)
        for(int j=2; j<=m; j++)
            if(a[i][j]&&a[i][j-1]) l[i][j] = l[i][j-1];
    for(int i=1; i<=n; i++)
        for(int j=m-1; j>0; j--)
            if(a[i][j]&&a[i][j+1]) r[i][j] = r[i][j+1];
    dl[ax] = l[ax][ay], dr[ax] = r[ax][ay];
    for(int i=ax-1; i>=1; i--) 
    {
        dl[i] = max(dl[i+1], l[i][ay]);
        dr[i] = min(dr[i+1], r[i][ay]);
    }
    for(int i=ax+1; i<=n; i++)
    {
        dl[i] = max(dl[i-1], l[i][ay]);
        dr[i] = min(dr[i-1], r[i][ay]);
    }
    int ans = 1, L = ay, R = ay, U = ax, D = ax;
    for(int up=1; ax-up+1>=1; up++)
    {
        int x = ax - up + 1;
        if(!a[x][ay]) break;
        for(int dwn=1; ax+dwn-1<=n; dwn++)
        {
            int y = ax + dwn - 1;
            if(!a[y][ay]) break;
            int cl = max(dl[x], dl[y]), cr = min(dr[x], dr[y]);
            if((cr-cl+1)*(y-x+1)>ans) ans = (cr-cl+1)*(y-x+1), L = cl, R = cr, U = x, D = y;
        }
    }
    for(int i=U; i<=D; i++)
        for(int j=L; j<=R; j++) t[i][j] = 'a';
    cout << U << " " << D << " " << L << " " << R << endl;
    return;
    t[ax][ay] = 'A';
    work(1, U-1, 1, m);
    work(U, D, 1, L-1);
    work(U, D, R+1, m);
    work(D+1, n, 1, m);
}
int main()
{
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++) scanf("%s", s[i]+1);
    for(int i=1; i<=n; i++) 
        for(int j=1; j<=m; j++) 
        {
            if(s[i][j]=='.'||s[i][j]=='A') a[i][j] = 1;
            else a[i][j] = 0;
            if(s[i][j]=='A') ax = i, ay = j;
        }
    gao();
   // for(int i=1; i<=n; i++) printf("%s\n", t[i]+1);
    return 0;
}
