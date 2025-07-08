#include <bits/stdc++.h>
using namespace std;
long long n,pos[100005],j=1,res=1;
pair<long long,long long> a[100005];
int main()
{
    if (fopen("CAU2.INP","r"))
    {
        freopen("CAU2.INP","r",stdin);
        freopen("CAU2.OUT","w",stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++)
        pos[i]=a[i].second;
    while (j<n)
    {
        if (pos[j]>pos[j+1])
            res++;
        j++;
    }
    cout<<res;
    return 0;
}
