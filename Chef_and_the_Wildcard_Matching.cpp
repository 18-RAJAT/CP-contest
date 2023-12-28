#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.size(),m=s2.size();
    if(n!=m)
    {
        cout<<"No"<<endl;
        return;
    }
    bool ok=false;
    for(int i=0;i<n;++i)
    {
        if(s1[i]=='?' || s2[i]=='?' || s1[i]==s2[i] || s1[i]==s2[i] || s1[i]=='?' && s2[i]=='?' || s1[i]=='?' && s2[i]!='?' || s1[i]!='?' && s2[i]=='?')
        {
            ok=true;
        }
        else
        {
            ok=false;
            break;
        }
    }
    cout<<(ok?"Yes":"No")<<endl;
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