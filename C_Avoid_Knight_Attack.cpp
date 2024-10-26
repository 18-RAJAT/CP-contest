#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>vp(m);
    for(int i=0;i<m;i++)
    {
        cin>>vp[i].first>>vp[i].second;
    }
    sort(vp.begin(),vp.end());
    vector<pair<int,int>>attack,moves={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
    for(auto it:vp)
    {
        for(auto it2:moves)
        {
            int x=it.first+it2.first;
            int y=it.second+it2.second;
            if(x>=1&&x<=n&&y>=1&&y<=n)
            {
                attack.push_back({x,y});
            }
        }
    }
    sort(attack.begin(),attack.end());
    attack.erase(unique(attack.begin(),attack.end()),attack.end());
    int ans=0,i=0,j=0;
    int p=attack.size(),q=vp.size();
    while(i<p)
    {
        if(j>=q)
        {
            ans+=p-i;
            break;
        }
        if(attack[i]<vp[j])
        {
            ans++;
            i++;
        }
        else if(attack[i]==vp[j])
        {
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
    cout<<n*n-ans-m<<endl;
}
signed main()
{
    sol();
    return 0;
}