#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
string s;
int func(int start,int end)
{
    int temp=-100005;
    int ans=0;
    for(int i=start;i<=end;++i)
    {
        // temp=temp*10+(s[i]-'0');
        // ans+=temp;
        if(s[i]=='1')
        {
            if(temp!=i && temp!=i-1)// && temp!=i-2)
            {
                temp=i+1,ans++;
            }
        }
    }
    return ans;
}
void sol()
{
    cin>>n>>s;
    int ans=0;
    for(int i=0;i<n;++i)
    {
        for(int j=i;j<n;++j)
        {
            ans+=func(i,j);
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