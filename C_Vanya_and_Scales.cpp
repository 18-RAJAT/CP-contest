#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int w,m;
    cin>>w>>m;
    int ans=0;
    if(w<4)
    {
        cout<<"YES";
        return;
    }
    do
    {
        int rem=ans+m%w;
        m/=w,ans=0;
        if(rem==0 || rem==1)continue;
        if(rem==w || rem==w-1)
        {
            ans++;continue;
        }
        cout<<"NO";
        return;
    }while(m);
    cout<<"YES";
}
signed main()
{
    sol();
    return 0;
}