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
    int ans=0,maxima=1e9;
    for(;;)
    {
        bool bits=1;
        for(int i=0;i<n;++i)
        {
            ans+=a[i];
            bits&=(a[i]==0?1:0);
        }
        if(bits)
        {
            break;
        }
        int res=0;
        map<int,int>fz;
        fz.clear();
        for(int i=0;i<n;++i)
        {
            fz[a[i]]++;
            if(fz[a[i]]==2)
            {
                res=max(res,a[i]);
            }
            a[i]=res;
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