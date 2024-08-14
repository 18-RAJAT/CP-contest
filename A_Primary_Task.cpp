#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    int n=s.size();
    if(n<3){cout<<"NO"<<endl;return;}
    if(s[0]=='1' && s[1]=='0')
    {
        string ans="";
        for(int i=2;i<n;++i)ans+=s[i];
        int x=0;
        x=stoi(ans);
        cout<<((x>1 && s[2]!='0')?"YES":"NO")<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
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