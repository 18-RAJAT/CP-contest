#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt=0;
    for(int i=0;i<n;++i)
    {
        if((s[i]-'0')%2==1)
        {
            cnt++;
        }
    }
    if(cnt<2)
    {
        cout<<-1<<endl;
        return;
    }
    int ans=0;
    for(int i=0;i<n;++i)
    {
        if((s[i]-'0')%2==1)
        {
            cout<<s[i];
            ans++;
        }
        if(ans==2)
        {
            break;
        }
    }
    cout<<endl;
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