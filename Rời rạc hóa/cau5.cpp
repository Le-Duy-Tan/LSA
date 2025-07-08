#include <bits/stdc++.h>
using namespace std;
long long t,n,x,vt;
pair<long long,long long> a[200005];
deque<long long> v;
bool cmp(pair<long long,long long> x,pair<long long,long long> y)
{
    return x.second>y.second;
}
int main()
{
    if (fopen("CAU5.INP","r"))
    {
        freopen("CAU5.INP","r",stdin);
        freopen("CAU5.OUT","w",stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while (t--)
    {
        cin>>n; v.clear();
        for (int i=1;i<=n;i++) cin>>a[i].first;
        for (int i=1;i<=n;i++) cin>>a[i].second;
        sort(a+1,a+1+n,cmp);
        for (int i=1;i<=n;i++)
        {
            x=a[i].first;
            if (v.size()==0) v.push_back(x);
            else
            {
                if (x<v.front()) v.push_front(x);
                else
                {
                    vt=lower_bound(v.begin(),v.end(),x)-v.begin()-1;
                    v[vt]=x;
                }
            }
        }
        cout<<v.size()<<'\n';
    }
    return 0;
}
