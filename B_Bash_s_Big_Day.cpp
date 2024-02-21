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
    map<int,int>mp;
    for(int i=0;i<n;++i)
    {
        int temp=arr[i];
        for(int j=2;j*j<=temp;++j)
        {
            if(temp%j==0)
            {
                mp[j]++;
                while(temp%j==0)
                {
                    temp/=j;
                }
            }
        }
        mp[temp]++;
    }
    int ans=1;
    for(int i=2;i<=1000000;++i)
    {
        ans=max(ans,mp[i]);
    }
    mp.clear();
    cout<<ans<<endl;
}
signed main()
{
    sol();   
    return 0;
}