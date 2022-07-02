#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using    namespace __gnu_pbds;
using    namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 998244353 //1000000007
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
#define srt(v) sort(v.begin(),v.end())
ll int a[1000005],b[1000005],c[1000005],d[1000005];
long long int mod_inverse(long long int x,long long int p)//x is fact[i] and p is M-2
{
    long long int res=1,y=p;
    while(y>0)
    {
        if(y&1) res=((res%M)*(x%M))%M;
        y=y>>1;
        x=((x%M)*(x%M))%M;
    }
    return res;
}
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int main()
{
    fast;
    ll int te,i,j,k,n,m,w,l,r,x,y,z,l2,r2,k1;
    te=1;
    b[0]=a[0]=c[0]=d[0]=1;
    fr(i,1000002,1)b[i]=(b[i-1]*i)%M,a[i]=(a[i-1]*2LL)%M,c[i]=(c[i-1]*a[i-1])%M,d[i]=(d[i-1]*(a[i]-1+M))%M;
    b[1000002]=mod_inverse(b[1000002],M-2);
    rfr(i,1000001,0)b[i]=(b[i+1]*(i+1))%M;
    cin>>te;
    fr(w,te,1)
    {
        cin>>n>>k;
        if(n>k)
        {
            cout<<0<<endl;
            ct;
        }
        x=(d[k]*mod_inverse(d[k-n],M-2))%M;
        x=(x*c[n])%M;
        x=(x*b[n])%M;
        cout<<x<<endl;
    }
}



