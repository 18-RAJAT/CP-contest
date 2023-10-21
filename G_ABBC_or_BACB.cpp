#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    vector<int>a;
    int cnt=0;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]=='A')
        {
            cnt++;
        }
        else
        {
            a.push_back(cnt);
            cnt=0;
        }
    }
    if(s.back()=='B')
    {
        a.push_back(0);
    }
    else
    {
        a.push_back(cnt);
    }
    int sum=0,mn=INT_FAST16_MAX;
    for(int i=0;i<a.size();++i)
    {
        sum+=a[i];
        mn=min(mn,a[i]);
    }
    cout<<max(0ll,sum-mn)<<endl;
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