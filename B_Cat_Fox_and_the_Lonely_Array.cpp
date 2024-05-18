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
    int ans=0;

    for(int i=0;i<25;++i)
    {
        int bits=0,temp=-1;
        bool flag=false;
        for(int j=0;j<n;++j)
        {
            if((a[j]>>i)&1)
            {
                flag=true;
                bits=max(bits,j-temp-1),temp=j;
            }
        }
        if(flag)bits=max(bits,n-temp-1);
        ans=max(ans,bits);
    }
    cout<<1+ans<<endl;
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