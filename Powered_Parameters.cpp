#include<bits/stdc++.h>
using namespace std;
#define int long long 
void sol()
{
    int n;
    cin>>n;
    map<int,int>mp;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        mp[i]=x;
    }
    int ans=0;
    for(int i=0;i<n;++i)
    {
        if(mp[i]==1)ans+=n;
        else
        {
            int Powered=1;
            for(int j=0;j<n;++j)
            {
                if(LLONG_MAX/mp[i]<Powered)break;
                assert(Powered>0);
                Powered*=mp[i];
                if(Powered<=mp[j])ans++;;
            }
        }
    }
    cout<<ans<<endl;
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