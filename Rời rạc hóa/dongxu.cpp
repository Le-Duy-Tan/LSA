#include <bits/stdc++.h>
using namespace std;
long long n,m,l,r,d[100005],curval,curpos,maxx=0;
unordered_map<long long,long long> added,a;
vector<long long> v;
int main()
{
    if (fopen("DONGXU.INP","r"))
    {
        freopen("DONGXU.INP","r",stdin);
        freopen("DONGXU.OUT","w",stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    while (m--)
    {
        cin>>l>>r;
        if (l<=r)
        {
            a[l]++;
            if (added[l]==0)
            {
                v.push_back(l);
                added[l]++;
            }
            if (r<n)
            {
                r++;
                a[r]--;
                if (added[r]==0)
                {
                    v.push_back(r);
                    added[r]++;
                }
            }
        }
        else
        {
            a[l]++;
            if (added[l]==0)
            {
                v.push_back(l);
                added[l]++;
            }
            a[1]++;
            if (added[1]==0)
            {
                v.push_back(1);
                added[1]++;
            }
            r++;
            a[r]--;
            if (added[r]==0)
            {
                v.push_back(r);
                added[r]++;
            }
        }
    }
    v.push_back(n+1);
    sort(v.begin(),v.end());
    curval+=a[v[0]];
    for (int i=1;i<v.size();i++)
    {
        d[curval]+=(v[i]-v[i-1]);
        curval+=a[v[i]];
        maxx=max(maxx,curval);
    }
    cout<<maxx<<" "<<d[maxx];
    return 0;
}
