#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    int n=s.size();
    int i=n-1;
    while(i>=0 && s[i]=='0')
    {
        i--;
    }
    int j=i;
    while(j>=0 && s[j]>='0' && s[j]<='9')
    {
        j--;
    }
    if(j<0)
    {
        cout<<s<<endl;
        return;
    }
    int k=j;
    while(k>=0 && s[k]=='0')
    {
        k--;
    }
    if(k<0)
    {
        cout<<s<<endl;
        return;
    }
    if(k<j)
    {
        cout<<s.substr(0,k+1)<<s.substr(j,i-j+1)<<endl;
        return;
    }
    cout<<s.substr(0,j+1)<<s.substr(i,s.size()-i)<<endl;
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