#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    array<int,2>a={0,0};
    string str;
    for(int i=0;i<n;++i)
    {
        if(i>=1 && s[i]=='0' && s[i]==s[i-1])
        {
            continue;
        }
        str.push_back(s[i]);
    }
    for(int i=0;i<str.size();++i)
    {
        a[str[i]-'0']++;
    }
    if(a[0]<a[1])
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
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