#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(n>26)
    {
        cout<<-1;
        return;
    }
    int ans=0;
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            if(s[i]==s[j])
            {
                ans++;
                break;
            }
        }
    }
    cout<<ans;
}
signed main()
{
    sol();
    return 0;
}