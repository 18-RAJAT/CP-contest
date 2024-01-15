#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    int ans=0;
    int c1=0,c2=0;
    for(int i=0;i<n;++i)
    {
        if(a[i]=='1')
        {
            c1++;
        }
        if(b[i]=='1')
        {
            c2++;
        }
    }
    if(c1==c2)
    {
        int ans=0;
        for(int i=0;i<n;++i)
        {
            if(a[i]=='1' && b[i]=='0')
            {
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    else if(c2<c1)
    {
        //logic: c1-c2 is the number of cats that are not in the right place in a and b both and c2-cats is the number of cats that are in the right place in a but not in b so we need to move them to the right place in b
        int ans=c1-c2;
        int cats=0;
        for(int i=0;i<n;++i)
        {
            if(a[i]=='1' && b[i]=='1')
            {
                cats++;
            }
        }
        ans+=(c2-cats);
        cout<<ans<<endl;
    }
    else if(c2>c1)
    {
        int ans=c2-c1;
        int cats=0;
        for(int i=0;i<n;++i)
        {
            if(a[i]=='1' && b[i]=='1')
            {
                cats++;
            }
        }
        ans+=(c1-cats);
        cout<<ans<<endl;
    }
    else
    {
        int ans=c2-c1;
        for(int i=0;i<n;++i)
        {
            if(a[i]=='1' && b[i]=='0')
            {
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    //range
    assert(ans>=0 && ans<=n);
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