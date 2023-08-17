#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int n=s.length();
        if(s=="()") {cout<<"NO\n";continue;}
        string ans="";
        for(int i=0;i<n;i++) ans+="()";
        cout<<"YES\n";
        if(ans.find(s)==string::npos) cout<<ans<<"\n";
        else
        {
            for(int i=0;i<n;i++) cout<<"(";
            for(int i=0;i<n;i++) cout<<")";
            cout<<"\n";
        }        
    }
    return 0;
}