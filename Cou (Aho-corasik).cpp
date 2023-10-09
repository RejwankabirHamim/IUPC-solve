//https://toph.co/arena?practice=6523a4d46f6e471c8e85b735#!/p/65025a99c723243c43490144
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using    namespace __gnu_pbds;
using    namespace std;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M   998244353 //1000000007  //
#define ll long long
#define pa pair<ll,ll>
#define ff first
#define ss second
#define pb push_back
#define pi acos(-1.0)
#define vi vector<int>
#define vll vector<ll>
#define fr(i,n,j) for(i=j;i<=n;i++)
#define rfr(i,n,j) for(i=n;i>=j;i--)
#define ct continue;
#define yo cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define endl '\n'
ll ar[500005],br[500005],cr[500005],dr[500005];
const int MAXT = 1000005;  // Length of Text
const int MAXP = 1000005;  // Sun of all |Pattern|
const int MAXQ = 1000005;  // Number of Patterns

int n;
int Next[MAXP][10];
int Root;                 // AC automaton Root
int Nnode;                // Total node count
int Link[MAXP];           // failure links
int Len[MAXP];            // Len[i] = length of i-th pattern
vector<int> End[MAXP];    // End[i] = indices of patterns those end in node i
// vector<int> Occ[MAX];  // Occ[i] = occurrences of i-th pattern
vector<int> edgeLink[MAXP];
vector<int> perNodeText[MAXP];

int in[MAXQ], out[MAXQ];
int euler[MAXT];
int Time;

void Clear(int node){
    for(int i=0;i<=9;i++)Next[node][i]=0;
    End[node].clear();
    edgeLink[node].clear();
    perNodeText[node].clear();
}

void init(){
    Time = 0;
    Root = Nnode = 0;
    Clear(Root);
}

void insertword(string p,int ind){
    int len = p.size();
    int now = Root;
    for(int i=0; i<len; i++){
        if(!Next[now][p[i]-'0']){
            Next[now][p[i]-'0'] = ++Nnode;
            Clear(Nnode);
        }
        now = Next[now][p[i]-'0'];
    }
    End[now].push_back(ind);
}

void push_links(){
    queue<int> q;
    Link[0] = -1;
    q.push(0);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        int ch=-1;
        for(auto edge : Next[u]){
            ch++;
            if(!edge)ct;
            int v = edge;
            int j = Link[u];
            while(j != -1 && !Next[j][ch]) j = Link[j];
            if(j != -1) Link[v] = Next[j][ch];
            else Link[v] = 0;
            q.push(v);
            for(int x : End[Link[v]]) End[v].push_back(x);
        }
    }
}

ll dp[20][1902][2];
ll cal(string s,int pos,int fail,int eq)
{
    if(End[fail].size())
    {
//        dbg(fail);
//        dbg(pos);
        return 0;
    }
    if(pos==19)return 1;
    if(dp[pos][fail][eq]!=-1)return dp[pos][fail][eq];
    ll ans=0,i;
    if(eq)
    {
        int x=s[pos]-'0';
        fr(i,x,0)
        {
            int now=fail;
            while(now != -1 && !Next[now][i]) now = Link[now];
            if(now!=-1) now = Next[now][i];
            else now = 0;
            if(i==x)ans+=cal(s,pos+1,now,1);
            else ans+=cal(s,pos+1,now,0);
        }
    }
    else
    {
        fr(i,9,0)
        {
            int now=fail;
            while(now != -1 && !Next[now][i]) now = Link[now];
            if(now!=-1) now = Next[now][i];
            else now = 0;
            ans+=cal(s,pos+1,now,0);
        }
    }
    return dp[pos][fail][eq]=ans;
}
int main()
{
    //fast;
    ll te,n,m,i,j,k,w1,x,y,z,l2,k2,k1,q,l,r;
    te=1;
    cin>>te;
    fr(w1,te,1)
    {
        init();
        cin>>n;
        fr(i,n,1)
        {
            string s;
            cin>>x;
            assert(x>0);
            s=to_string(x);
            //while(s.size()!=19)s='0'+s;
            insertword(s,i);
        }
        push_links();
        string s1,s2;
        cin>>l>>r;
        assert(l<=r);
        assert(l>0&&r>0);
        s2=to_string(r);
        l--;
        s1=to_string(l);
        while(s1.size()!=19)s1='0'+s1;
        while(s2.size()!=19)s2='0'+s2;
//        dbg(s1);
//        dbg(s2);
        memset(dp,-1,sizeof dp);
        z=cal(s2,0,0,1);
        //dbg(z);
        memset(dp,-1,sizeof dp);
        z-=cal(s1,0,0,1);
        cout<<"Case #"<<w1<<": "<<z<<endl;
    }
}
