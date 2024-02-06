#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    vector<int>res;
    for(int i=0;i<n;++i)
    {
        if(a[i]!=b[i])
        {
            res.push_back(i+1);
            res.push_back(1);
            res.push_back(i+1);
        }
    }
    cout<<res.size()<<" ";
    for(int i=0;i<res.size();++i)
    {
        cout<<res[i]<<" ";
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