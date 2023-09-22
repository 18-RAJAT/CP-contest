#include<bits/stdc++.h>
using namespace std;
#define int long long

int dp[26],ndp[26];
string s,t;
int convert(char c)
{
    return c-'a';
    assert(c>='a' && c<='z');
}
void take()
{
    memset(dp,0,sizeof(dp));
    memset(ndp,0,sizeof(ndp));
    for(auto& val:s)
    {
        dp[convert(val)]++;
    }
    for(auto& val:t)
    {
        ndp[convert(val)]++;
    }
}
void sol()
{
    int n;
    cin>>n;
    cin>>s>>t;
    take();
    int ok=1;
    for(int i=0;i<26;i++)
    {
        if(dp[i]!=ndp[i])
        {
            ok=0;
            break;
        }
    }
    for(auto& it:t)
    {
        if(s.find(it)==string::npos)
        {
            cout<<-1<<endl;
            return;
        }
        if(!ok)
        {
            cout<<-1<<endl;
            return;
        }
    }
    vector<int>ans;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]!=t[i])
        {
            bool was=false;
            for(int j=i+1;j<n;++j)
            {
                if(s[j]==t[i])
                {
                    for(int k=j;k>i;--k)
                    {
                        swap(s[k],s[k-1]);
                        ans.emplace_back(k);
                        was=true;
                    }
                    if(was)
                    {
                        break;
                    }
                }
            }
        }
    }
    cout<<ans.size()<<endl;
    for(auto& it:ans)
    {
        cout<<it<<" ";
    }
}
signed main()
{
    sol();
    return 0;
}