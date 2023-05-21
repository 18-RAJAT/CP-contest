#include<bits/stdc++.h>
using namespace std;

 main()
{
    long long int tc;
    scanf("%d",&tc);
    while(tc-->0)
    {
        long long int n,m,x;
        scanf("%d%d",&n,&m);
        vector<pair<long long int,long long int>>pairs;
        map<long long int,long long int>mp;
        for(long long int i=0;i<n;++i)
        {
            scanf("%d",&x);
            mp[x]++;
        }
        for(auto& it:mp)
        {
            pairs.emplace_back(make_pair(it.first,it.second));
        }
        n=pairs.size();
        sort(pairs.begin(),pairs.end());
        long long int ans=0,temp=1;

        for(long long int i=0;i<m-1;++i)
        {
            temp*=pairs[i].second;
            temp%=1000000007;
        }
        for(long long int i=m-1;i<n;++i)
        {
            temp*=pairs[i].second;
            temp%=1000000007;
            if(pairs[i].first-pairs[i-m+1].first<m)
            {
                ans+=temp;
            }
            temp/=pairs[i-m+1].second;
            // cout<<temp<<" "<<ans<<"\n";
        }
        cout<<ans<<"\n";
    }
    return 0;
}