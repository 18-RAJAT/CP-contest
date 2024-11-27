#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,q;
    cin>>n>>q;
    vector<string>a(n);
    unordered_map<string,int>mp;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        mp[a[i]]=i;
    }
    vector<int>cost(n-1);
    for(int i=0;i<n-1;++i)cin>>cost[i];
    vector<vector<int>>arr(n,vector<int>(n,0));
    for(int i=0;i<n;++i)
    {
        int res=0;
        for(int j=i;j<n-1;++j)
        {
            res+=cost[j];
            arr[i][j+1]=res;
        }
    }
    for(int i=0;i<q;++i)
    {
        string s;
        int x;
        cin>>s>>x;
        int init=mp[s],tmp=init;
        for(int j=init+1;j<n;++j)
        {
            if (arr[init][j]<=x)
            {
                tmp=j;
            }
            else
            {
                break;
            }
        }
        cout<<a[tmp]<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}