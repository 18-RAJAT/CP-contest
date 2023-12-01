#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int arr[n][n];
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cin>>arr[i][j];
        }
    }
    int ans[n];
    memset(ans,0,sizeof(ans));
    for(int j=0;j<n;++j)
    {
        int cnt=0;
        for(int i=0;i<n;++i)
        {
            if(i==0 && i!=j)
            {
                cnt=arr[i][j];
            }
            else if(i==1 && j==0)
            {
                cnt=arr[i][j];
            }
            else if(i!=j)
            {
                cnt&=arr[i][j];
            }
        }
        ans[j]=cnt;
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(i!=j)
            {
                if(arr[i][j]!=(ans[i]|ans[j]))
                {
                    cout<<"NO"<<endl;
                    return;
                }
            }
        }
    }
    cout<<"YES"<<endl;
    for(int i=0;i<n;++i)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    
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