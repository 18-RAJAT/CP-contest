#include<bits/stdc++.h>
using namespace std;
#define int long long
bool palindrome(string s)
{
    int n=s.size();
    for(int i=0;i<n;++i)
    {
        if(s[i]!=s[n-i-1])return false;
    }
    return true;
}
void sol()
{
    string s;
    cin>>s;
    int n=s.size();
    bool ok=false;
    for(int i=0;i<n;++i)
    {
        if(n%2==1 && i==n/2)continue;
        if(s[0]!=s[i])ok=true;
    }
    if(s.size()==1)
    {
        cout<<"YES\n1\n"<<s<<endl;
        return;
    }
    if(!ok)
    {
        cout<<"NO";
        return;
    }
    cout<<"YES"<<endl;
    if(!palindrome(s))
    {
        cout<<"1\n"<<s;
        return;
    }
    else if(~n&1)
    {
        cout<<"2\n"<<s[0]<<" "<<s.substr(1);
        return;
    }
    else if(s[0]!=s[n-1])
    {
        cout<<"2\n"<<s[0]<<" "<<s.substr(1);
        return;
    }
    int i=1;
    while(s[0]==s[i])i++;
    for(;i<n;++i)
    {
        if(!palindrome(s.substr(0,i+1)) && !palindrome(s.substr(i+1)))
        {
            cout<<"2\n"<<s.substr(0,i+1)<<" "<<s.substr(i+1);
            return;
        }
    }
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        sol();
        cout<<endl;
    }
    return 0;
}