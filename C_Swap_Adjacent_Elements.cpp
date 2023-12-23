#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int a[n],pre_computed[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    string s;
    cin>>s;
    pre_computed[0]=0;
    auto convert=[](char c)->int
    {
        return c-'0';
    };
    for(int i=1;i<n;++i)
    {
        pre_computed[i]=pre_computed[i-1]+convert(s[i-1]);
    }
    int check=-1;
    for(int i=0;i<n;++i)
    {
        // cout<<"comparing "<<a[i]-1<<" and "<<i<<"\n";
        // for(int j=i-1;~j;--j)
        // {
        //     if(a[j]==a[i]-1)
        //     {
        //         check=j;
        //         break;
        //     }
        // }
        if(a[i]!=(i+1))
        {
            if(check>=(a[i]-1))
            {
                continue;
            }
            if((pre_computed[a[i]-1]-pre_computed[i])!=(a[i]-1)-i)
            {
                cout<<"NO\n";
                return;
            }
            check=a[i]-1;
        }
    }
    cout<<"YES";
}
signed main()
{
    sol();
    return 0;
}