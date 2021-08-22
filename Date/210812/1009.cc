#include <bits/stdc++.h>
using namespace std;

struct AC_Automata{
#define N 100010
    int tire[N][26];//字典树
    int val[N];//字符串结尾标记
    int fail[N];//失配指针
    int last[N];//last[i]=j表j节点表示的单词是i节点单词的后缀，且j节点是单词节点
    int tot;//编号
    int time[N];//上次的单词出现在文本串的位置
    int len[N];//单词节点的长度
    int cnt[N][2];//计数
 
    void init(){//初始化0号点
        tot=1;
        val[0]=0;
        last[0]=0;
        fail[0]=0;
        memset(tire[0],0,sizeof(tire[0]));
    }
 
    void insert(char *s){//构造trie
        int sLen=strlen(s);
        int root=0;
        for(int i=0;i<sLen;i++){
            int id=s[i]-'a';
            if(tire[root][id]==0){
                tire[root][id]=tot;
                memset(tire[tot],0,sizeof(tire[tot]));
                val[tot++]=0;
            }
            root=tire[root][id];
        }
        val[root]=1;
        time[root]=0;
        len[root]=sLen;
        cnt[root][0]=0;
        cnt[root][1]=0;
    }
 
    void build(){//构造fail与last
        queue<int> q;
        for(int i=0;i<26;i++){
            int root=tire[0][i];
            if(root!=0){
                fail[root]=0;
                last[root]=0;
                q.push(root);
            }
        }
 
        while(!q.empty()){//bfs求fail
            int k=q.front();
            q.pop();
            for(int i=0;i<26; i++){
                int u=tire[k][i];
                if(u==0)
                    continue;
                q.push(u);
 
                int v=fail[k];
                while(v && tire[v][i]==0)
                    v=fail[v];
                fail[u]=tire[v][i];
                last[u]=val[fail[u]]?fail[u]:last[fail[u]];
            }
        }
    }
 
    void query(char *s){//匹配
        int len=strlen(s);
        int j=0;
        for(int i=0;i<len;i++){
            int id=s[i]-'a';
            while(j && tire[j][id]==0)
                j=fail[j];
            j=tire[j][id];
            if(val[j])
                print(j,i+1);
            else if(last[j])
                print(last[j],i+1);
        }
    }
 
    void print(int i,int pos){
        if(val[i]){
            cnt[i][0]++;
            if(time[i]+len[i]<=pos){
                time[i]=pos;
                cnt[i][1]++;
            }
            print(last[i],pos);
        }
    }
 
    int queryT(char *s,int op){
        int len=strlen(s);
        int root=0;
        for(int i=0;i<len;i++){
            int id=s[i]-'a';
            root=tire[root][id];
        }
        return cnt[root][op];
    }
};

void solve(){

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned _TvT_;
    cin >> _TvT_;
    for(unsigned i = 1; i <= _TvT_; ++i){
        solve();
    }

    return 0;
}