#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<string>ans;
    int last=n-1;
    while(last>=0)
    {
        if(s[last]=='b' || s[last]=='c' || s[last]=='d')
        {
            ans.push_back(s.substr(last-2,3));
            last-=3;//for check the next 3 characters
        }
        else
        {
            ans.push_back(s.substr(last-1,2));
            last-=2;//for check the next 2 characters
        }
    }
    int sza=ans.size();
    for(int i=sza-1;~i;--i)
    {
        cout<<ans[i];
        if(i)
        {
            cout<<".";
        }
    }
    cout<<endl;
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