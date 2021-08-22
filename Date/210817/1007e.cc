#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define ch(a) (int(a-'a')+1)
#define mm(a) memset(a,0,sizeof(a))
#define Erica_1031 Errrica'u'
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define inf  0x7FFFFFFF
#define sset set<int>::iterator it=a.begin();it!=a.end();it++
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
const int Maxx=2*1e5+22;
long long mod=998244353;
vector<int>le;
vector<int>ri;
int visl[1000005];
int visr[1000005];
int q;string s;int num,nm;int now;
int cntl,cntr;
string ss;
int main()
{
    num=0,cntl=0,cntr=0,now=0;IOS;cin>>q;
    while(q--)
    {
        cin>>s;if(s=="G") cin>>nm;

        if(s=="L")
        {
            ++num;++cntl;le.push_back(num);ss+="L";visl[num]=cntl;++now;
            cout << num << " " << cntl << " " << now << endl;
        }
         else if(s=="R")
        {
            div();
            ++num;++cntr;ri.push_back(num);ss+="R";visr[num]=cntr;++now;
        }
        else if(s=="G")
        {
            
            //cout<<ss[nm-1]<<endl;
            if(ss[nm-1]=='L') le.erase(le.begin()+visl[nm]-1,le.begin()+visl[nm]);
            else ri.erase(ri.begin()+visr[nm]-1,ri.begin()+visr[nm]);--now;
            //for(auto p:le) cout<<p<<" ";cout<<endl;
            //for(auto p:ri) cout<<p<<" ";cout<<endl;
        } 
         else
        {
            if(le.size()>=(now+2)/2) cout<<le[le.size()-(now+2)/2]<<endl;
            else cout<<ri[(now+2)/2-le.size()-1]<<endl;
        } 

    }
    return 0;
}