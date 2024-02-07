#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int start=0,end=n-1;
    for(int i=0;i<n;++i)
    {
        if(s[i]=='B')
        {
            start=i;
            break;
        }
    }
    for(int i=n-1;~i;--i)
    {
        if(s[i]=='B')
        {
            end=i;
            break;
        }
    }
    if(start>end)
    {
        cout<<0<<endl;
        return;
    }
    cout<<end-start+1<<endl;
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