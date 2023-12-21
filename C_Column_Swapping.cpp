#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>a(n,vector<int>(m));
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cin>>a[i][j];
        }
    }
    int l=-1,r=-1;
    for(int i=0;i<n;++i)
    {
        vector<int>temp=a[i];
        sort(temp.begin(),temp.end());
        int ans=0;
        for(int j=0;j<m;++j)
        {
            ans+=a[i][j]!=temp[j];
        }
        if(ans>=3)
        {
            cout<<"-1\n";
            return;
        }
        if(ans>=1)
        {
            for(int j=0;j<m;++j)
            {
                if(a[i][j]!=temp[j])
                {
                    l==-1?l=j:r=j;
                }
            }
            break;
        }
    }
    if(l==-1)
    {
        cout<<"1 1\n";
        return;
    }
    for(int i=0;i<n;++i)
    {
        swap<int>(a[i][l],a[i][r]);
    }
    for(int i=0;i<n;++i)
    {
        for(int j=1;j<m;++j)
        {
            if(a[i][j]<a[i][j-1])
            {
                cout<<"-1\n";
                return;
            }
        }
    }
    cout<<l+1<<' '<<r+1<<'\n';
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