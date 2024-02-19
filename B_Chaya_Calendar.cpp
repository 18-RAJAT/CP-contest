#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
    }
    int ans=arr[0];
    for(int i=1;i<n;++i)
    {
        if(arr[i]>ans)
        {
            ans=arr[i];
        }
        else
        {
            int div=ans/arr[i];
            (div*arr[i]>ans)?ans=div*arr[i]:ans=(div+1)*arr[i];
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