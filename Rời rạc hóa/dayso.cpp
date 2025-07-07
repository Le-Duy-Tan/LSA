#include <bits/stdc++.h>
using namespace std;
long long n,a[100005],s[100005],l,r,st[12000005],start,endd,res=0;
unordered_map<long long,long long> d;
vector<long long> v;
void build(long long node,long long u,long long v)
{
    if (u==v)
    {
        st[node]=0;
        return;
    }
    long long mid=(u+v)/2;
    build(node*2,u,mid);
    build (node*2+1,mid+1,v);
}
void update(long long node,long long u,long long v,long long x)
{
    if (u==v)
    {
        st[node]++;
        return;
    }
    long long mid=(u+v)/2;
    if (mid>=x) update(node*2,u,mid,x);
    else update(node*2+1,mid+1,v,x);
    st[node]=st[node*2]+st[node*2+1];
}
long long get(long long node,long long u,long long v,long long x,long long y)
{
    if (v<x||u>y) return 0;
    if (u>=x&&v<=y) return st[node];
    long long mid=(u+v)/2;
    return get(node*2,u,mid,x,y)+get(node*2+1,mid+1,v,x,y);
}
long long get_id(long long x)
{
    return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
int main()
{
    if (fopen("CUOCTHI.INP","r"))
    {
        freopen("CUOCTHI.INP","r",stdin);
        freopen("CUOCTHI.OUT","w",stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>l>>r;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
        if (d[s[i]]==0)
        {
            v.push_back(s[i]);
            d[s[i]]++;
        }
        if (d[s[i]-l]==0)
        {
            v.push_back(s[i]-l);
            d[s[i]-l]++;
        }
        if (d[s[i]-r]==0)
        {
            v.push_back(s[i]-r);
            d[s[i]-r]++;
        }
    }
    if (d[0]==0) v.push_back(0);
    sort(v.begin(),v.end());
    build(1,1,v.size());
    update(1,1,v.size(),get_id(0));
    for (int i=1;i<=n;i++)
    {
        start=get_id(s[i]-r);
        endd=get_id(s[i]-l);
        res+=get(1,1,v.size(),start,endd);
        update(1,1,v.size(),get_id(s[i]));
    }
    cout<<res;
    return 0;
}
