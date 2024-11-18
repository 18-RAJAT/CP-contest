#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int k;
    cin>>k;
    vector<int>a(k);
    for(int i=0;i<k;++i)cin>>a[i];
    unordered_map<int,int>mp;
    for(int i=0;i<k;++i)mp[a[i]]++;
    int l=k-2,ok=0;
    pair<int,int>ans;
    for(int i=1;i<=sqrt(l);++i)
    {
        if(l%i!=0)continue;
        int m=l/i;
        if(mp.count(i) && mp.count(m))
        {
            if(i!=m)
            {
                ans={i,m};
                ok=1;
                break;
            }
            else
            {
                if(mp[i]>=2)
                {
                    ans={i,m};
                    ok=1;
                    break;
                }
            }
        }
    }
    if(ok)cout<<ans.first<<" "<<ans.second<<endl;
    else cout<<"1 1"<<endl;
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
    return 0;
}