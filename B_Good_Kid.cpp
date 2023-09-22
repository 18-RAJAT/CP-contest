#include<bits/stdc++.h>
using namespace std;
#define int long long
int find(int n,vector<int>&dig)
{
    int mn=*min_element(dig.begin(),dig.end());
    int idx=find(dig.begin(),dig.end(),mn)-dig.begin();
    dig[idx]+=1;
    int ans=1;
    for(int i=0;i<n;++i)
    {
        ans*=dig[i];
    }
    return ans;
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>d(n);
        for(int i=0;i<n;++i)
        {
            cin>>d[i];
        }
        cout<<find(n,d)<<"\n";
    }
    return 0;
}