#include<cstdio>
#include<cctype>
#include<algorithm>
#include<cstring>
typedef long long int64;
inline int getint() {
    char ch;
    while(!isdigit(ch=getchar()));
    int x=ch^'0';
    while(isdigit(ch=getchar())) x=(((x<<2)+x)<<1)+(ch^'0');
    return x;
}
const int N=1000001;
int a[N],pos[N],num[N],cnt[N*2];
int64 ans;
void solve(int l,int r) {
    if(l==r) {
        ans++;
        return;
    }
    const int mid=(l+r)/2;
    solve(l,mid);
    solve(mid+1,r);
    for(int i=mid;i>=l;i--) {
        if(++cnt[a[i]]>(mid-i+1)/2) {
            if(!pos[a[i]]) {
                num[pos[a[i]]=++num[0]]=a[i];
            }
        }
    }
    for(int i=mid+1;i<=r;i++) {
        if(++cnt[a[i]]>(i-mid)/2) {
            if(!pos[a[i]]) {
                num[pos[a[i]]=++num[0]]=a[i];
            }
        }
    }
    for(int i=l;i<=r;i++) {
        pos[a[i]]=cnt[a[i]]=0;
    }
    for(int i=1;i<=num[0];i++) {
        int sum=r-l+1,max=sum,min=sum;
        cnt[sum]=1;
        for(int j=l;j<mid;j++) {
            if(a[j]==num[i]) {
                sum++;
            } else {
                sum--;
            }
            max=std::max(max,sum);
            min=std::min(min,sum);
            cnt[sum]++;
        }
        if(a[mid]==num[i]) {
            sum++;
        } else {
            sum--;
        }
        for(int i=min;i<=max;i++) {
            cnt[i]+=cnt[i-1];
        }
        for(int j=mid+1;j<=r;j++) {
            if(a[j]==num[i]) {
                sum++;
            } else {
                sum--;
            }
            ans+=cnt[std::min(max,sum-1)];
        }
        for(int i=min;i<=max;i++) {
            cnt[i]=0;
        }
    }
    num[0]=0;
}
void work(){
    memset(pos,0,sizeof pos);
    memset(num, 0, sizeof num);
    memset(cnt, 0, sizeof cnt);
    int n = getint();
    for(int i = 1; i <= n; ++i) a[i] = getint();
    solve(1,n);
    printf("%lld\n",ans);
}
int main() {
    int t;
    scanf("%d", &t);
    while(t--) work();
    return 0;
}