#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    function<string(int,int)> constructString=[&](int n,int k)->string
    {
        string s="";
        for(int i=0;i<n;++i)
        {
            for(char ch='a';ch<'a'+k;++ch)
            {
                s+=ch;
            }
        }
        // cout<<s<<endl;
        return s;
    };
    cout<<constructString(n,k)<<endl;
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