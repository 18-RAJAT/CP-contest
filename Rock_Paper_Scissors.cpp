#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int count=0;
    int sza=s.size();
    for(int i=0;i<sza;++i)
    {
        if(s[i]=='R')
        {
            count++;
        }
    }
    if(n/2<count)
    {
        cout<<string(n,'P')<<endl;
    }
    else
    {
        string ans="";
        for(int i=n-1;~i;--i)
        {
            if(count<=n/2)
            {
                if(s[i]=='P')
                {
                    ans+='S';
                    count++;
                }
                else if(s[i]=='S')
                {
                    ans+='R';
                    count++;
                }
                else
                {
                    ans+='P';
                }
            }
            else
            {
                ans+='P';
            }
        }
        for(int i=ans.size()-1;~i;--i)
        {
            cout<<ans[i];
        }
        cout<<endl;
    }
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