#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    vector<map<array<int,2>,vector<int>>>mp(3);
    for(int i=0;i<n-2;++i)
    {
        mp[0][{a[i],a[i+1]}].push_back(a[i+2]);
        mp[1][{a[i],a[i+2]}].push_back(a[i+1]);
        mp[2][{a[i+1],a[i+2]}].push_back(a[i]);
    }
    map<int,int>pairs;
    int count=0;
    for(int i=0;i<3;++i)
    {
        for(auto& it:mp[i])
        {
            sort(it.second.begin(),it.second.end());
            pairs.clear();
            int beautiful=0;
            for(auto& itr:it.second)pairs[itr]++;
            for(auto& count_pairs:pairs)
            {
                beautiful+=count_pairs.second*(it.second.size()-count_pairs.second);
            }
            count+=beautiful/2;
        }
    }
    cout<<count<<endl;
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