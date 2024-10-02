#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int count=0;
    for(int i=0;i<n;++i)
    {
        if(s[i]=='1')count++;
    }
    cout<<max(n-k,count)<<endl;
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