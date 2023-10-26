#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int ans=0,check=0;
    bool flag=false;
    for(int i=0;i<n;++i)
    {
        if(s[i]=='0')
        {
            check++;
        }
        else
        {
            if(flag)
            {
                ans+=check/(k+1);
                check=0;
            }
            // else if(~flag)
            // {
            //     flag=false;
            //     check=0;
            //     ans=0;
            // }
            else
            {
                flag=true;
                if(k+1<=check)
                {
                    ans++;
                    check-=k+1;
                    ans+=check/(k+1);
                }
                check=0;
            }
        }
    }
    if(!flag)
    {
        ans++;
        check-=k+1;
        ans+=check/(k+1);
        // if(check%(k+1))
        // {
        //     ans++;
        // }
        // cout<<ans<<'\n';
        // return;
    }
    else
    {
        ans+=check/(k+1);
    }
    // cout<<check;//ok
    // ans+=check/(k+1);
    cout<<ans<<'\n';
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