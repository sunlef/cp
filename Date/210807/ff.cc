#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<set>
using namespace std;
inline int read(){
	int x=0; char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return x;
}
const int maxn=3e5+10;
struct Edge{ int to,next;}edge[maxn*4];
int h1[maxn],h2[maxn],cnt;
inline void addedge1(int u,int v){
	edge[++cnt].to=v,edge[cnt].next=h1[u],h1[u]=cnt;
}
inline void addedge2(int u,int v){
	edge[++cnt].to=v,edge[cnt].next=h2[u],h2[u]=cnt;
}
int n,st[maxn],ed[maxn],idx;
void dfs2(int x,int fr){
	st[x]=++idx;
	for(int i=h2[x];i;i=edge[i].next){
		int y=edge[i].to;
		if(y==fr) continue;
		dfs2(y,x);
	}
	ed[x]=++idx;
}
set<pair<int,int> > s;
inline int check(int x){
	set<pair<int,int> >::iterator it=s.lower_bound(make_pair(st[x],x));
	if(it!=s.end()&&ed[it->second]<ed[x]) return -2;
	if(it!=s.begin()&&ed[(--it)->second]>ed[x]) return it->second;
	return -1;
}
int ans;
void dfs1(int x,int fr){
	int tmp=check(x);
	if(tmp>0) s.erase(make_pair(st[tmp],tmp));
	if(tmp!=-2) s.insert(make_pair(st[x],x));
//	printf("%d :\n",x);
//	for(set<pair<int,int> >::iterator it=s.begin();it!=s.end();it++)
//		printf("(%d, %d) ",it->first,it->second);
//	puts("");
	ans=max(ans,(int)s.size());
	for(int i=h1[x];i;i=edge[i].next){
		int y=edge[i].to;
		if(y==fr) continue;
		dfs1(y,x);
	}
	if(tmp>0) s.insert(make_pair(st[tmp],tmp));
	if(tmp!=-2) s.erase(make_pair(st[x],x));
}
void solve(){
	for(int i=1;i<=n;i++) h1[i]=h2[i]=0; cnt=0;
	n=read();
	for(int i=2;i<=n;i++){
        int u = read();
        int v = read();
		addedge1(u,v);
        addedge1(v,u);
	}
	for(int i=2;i<=n;i++){
		int u = read();
        int v = read();
		addedge2(u,v);
        addedge2(v,u);;
	}
	idx=0; dfs2(1,0);
//	for(int i=1;i<=n;i++)
//		printf("st[%d] = %d, ed[%d] = %d\n",i,st[i],i,ed[i]);
	ans=0; dfs1(1,0);
	printf("%d\n",ans);
}
int main(){
	int T=read();
	while(T--) solve();
	return 0;
}