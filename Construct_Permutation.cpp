#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    if(n%2==0)
    {
        cout<<-1<<endl;
        return;
    }
    vector<int>p;
    for(int i=1;i<=n;++i)
    {
        if(i==1)p.push_back(1);
        else if(i%2==0)p.push_back(n-i+1);
        else p.push_back(i);
    }
    for(int i=0;i<p.size();++i)
    {
        if(i>0)cout<<" ";
        cout<<p[i];
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