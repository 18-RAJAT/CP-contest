#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int half=n/2;
    for(int i=0;i<half;++i)
    {
        if(s[i]=='0')
        {
            cout<<i+1<<" "<<n<<" "<<i+2<<" "<<n<<endl;
            return;
        }
    }
    for(int i=half;i<n;++i)
    {
        if(s[i]=='0')
        {
            cout<<1<<" "<<i+1<<" "<<1<<" "<<i<<endl;
            return;
        }
    }
    cout<<1<<" "<<n-1<<" "<<2<<" "<<n<<endl;
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