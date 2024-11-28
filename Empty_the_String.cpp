#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ans=0,a=0,b=0;
    for(auto& c:s)
    {
        if(c=='A')
        {
            if(b>0)
            {
                b--,a++;
            }
            else
            {
                ans++,a++;
            }
        }
        else if(c=='B')
        {
            if(a>0)
            {
                a--,b++;
            }
            else
            {
                ans++,b++;
            }
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