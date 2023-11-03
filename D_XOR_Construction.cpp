#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    int x=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        x^=a[i];
    }
    vector<int>b(n);
    int ans=0;
    for(int i=1;i<n;++i)
    {
        b[i]=b[i-1]^a[i-1];
        ans^=b[i];
    }
    b[0]=0;
    // int tmp=b[0];
    for(int i=0;i<31;++i)
    {
        int cnt=0;
        for(int j=0;j<n;++j)
        {
            auto f=[&](int x)->int
            {
                return (x>>i)&1;
            };
            if(f(b[j]))
            {
                cnt++;
            }
        }
        //left shift 
        // auto f=[&](int x)->int
        // {
        //     return (x<<1);
        // };
        // auto g=[&](int x)->int
        // {
        //     for(int j=0;j<31;++j)
        //     {
        //         if((x>>j)&1)
        //         {
        //             x^=(1<<j);
        //             break;
        //         }
        //     }
        //     return x;
        // };
        int cnt1=0;
        for(int j=0;j<n;++j)
        {
            auto f=[&](int x)->int
            {
                return (x>>i)&1;
            };
            if(f(j))
            {
                cnt1++;
            }
            // if((a[j]>>i)&1)
            // {
            //     cnt1++;
            // }
        }
        if(cnt!=cnt1)
        {
            b[0]|=(1<<i);
        }
    }
    // ~tmp;
    ~ans;
    for(int i=1;i<n;++i)
    {
        // b[i]^=tmp;
        b[i]^=b[0];
        // b[i]^=ans;
    }
    // assert(b[0]==ans);
    for(int i=0;i<n;++i)
    {
        cout<<b[i]<<" ";
    }
    cout<<endl;
}
signed main()
{
    sol();
    return 0;
}