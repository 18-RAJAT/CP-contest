#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    string sp,tp;
    for(int i=0;i<n;++i)
    {
        if(s[i]!='b')
        {
            sp.push_back(s[i]);
        }
        if(t[i]!='b')
        {
            tp.push_back(t[i]);
        }
    }
    if(sp!=tp)
    {
        cout<<"NO"<<endl;
        return;
    }
    int a=0,c=0;
    for(int i=0;i<n;++i)
    {
        a+=(s[i]=='a'?true:false);
        a-=(t[i]=='a'?true:false);
        c+=(t[i]=='c'?true:false);
        c-=(s[i]=='c'?true:false);

        if(a<0 || c<0)
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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