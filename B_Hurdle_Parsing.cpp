#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    int n=s.size(),count=0;
    vector<int>ans;
    for(int i=0;i<n;++i)
    {
        if(s[i]=='-')count++;
        else if(s[i]=='|')
        {
            if(count>=1)ans.push_back(count);
            count=0;
        }
    }
    for(int i=0;i<ans.size();++i)
    {
        if(i>=1)cout<<" ";
        cout<<ans[i];
    }
}
signed main()
{
    sol();
    return 0;
}