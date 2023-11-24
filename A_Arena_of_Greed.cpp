#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int ans=0,cnt=0;
    while(n>=1)
    {
        if(cnt%2==0)
        {
            if(n==1)
            {
                ans++;
                break;
            }
            if(n%4==0 && n!=4)
            {
                n--;
                ans++;
            }
            else
            {
                if(n%2==0)
                {
                    ans+=n/2;
                    n/=2;
                }
                else
                {
                    ans++;
                    n--;
                }
            }
        }
        else
        {
            if(n==1)
            {
                break;
            }
            if(n%4==0 && n!=4)
            {
                n--;
            }
            else
            {
                if(n%2==0)
                {
                    n/=2;
                }
                else
                {
                    n--;
                }
            }
        }
        cnt++;
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