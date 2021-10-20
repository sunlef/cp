
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
double a[100009];
double sum[100009];
int main()
{
    int n,len;
    scanf("%d%d",&n,&len);
    for(int i=1;i<=n;i++)
    {
        scanf("%lf",&a[i]);
    }
    double l=-1e7;
    double r=1e7;
    while(r-l>1e-5)
    {
        double mid=(l+r)/2;
        for(int i=1;i<=n;i++)
        {
            sum[i]=sum[i-1]+a[i]-mid;
        }
        double minn=1e9;
        double maxx=-1e9;
        for(int i=len;i<=n;i++)//这里多想一下就明白了。
        {
            minn=min(sum[i-len],minn);
            maxx=max(sum[i]-minn,maxx);
        }
        if(maxx>0)
        {
            l=mid;
        }
        else
        {
            r=mid;
        }
    }
    cout<<r<<endl;
}
