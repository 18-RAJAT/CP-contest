#include<bits/stdc++.h>
using namespace std;
#define int long long

void sol()
{
    int k;
    cin>>k;
    string s,t;
    cin>>s>>t;
    // if(s[0]==t[0] && s[s.size()-1]==t[t.size()-1])
    // {
    //     cout<<0<<endl;
    //     return;
    // }
    if(t[1]==t[2])
    {
        cout<<0<<endl;
        return;
    }
    int n=2*k+1;
    int q=0;
    for(int i=0;i<n;++i)
    {
        if(s[i]=='?' && t[i]=='?')
        {
            q++;
        }
    }
    int ans=0;
    for(int i=0;i<(1<<q);++i)
    {
        string s1=s;
        string t1=t;
        int x=i;
        for(int j=0;j<n;++j)
        {
            if(s1[j]=='?' && t1[j]=='?')
            {
                if(x%2==0)
                {
                    s1[j]='0';
                    t1[j]='1';
                }
                else
                {
                    s1[j]='1';
                    t1[j]='0';
                }
                x/=2;
            }
        }
        int cnt=0;
        for(int j=0;j<n;++j)
        {
            if(s1[j]=='0')
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
            if(cnt<0)
            {
                break;
            }
        }
        if(cnt>=0)
        {
            ans++;
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--)
    {
        sol();
    }
    return 0;
}