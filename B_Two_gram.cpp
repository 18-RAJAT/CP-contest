#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    map<string,int>freq;
    for(int i=0;i<n-1;++i)
    {
        string temp=s.substr(i,2);
        freq[temp]++;
    }
    int maxi=0;
    string ans="";
    for(auto& i:freq)
    {
        if(i.second>maxi)
        {
            maxi=i.second;
            ans=i.first;
        }
    }
    cout<<ans;
}
signed main()
{
    sol();
    return 0;
}