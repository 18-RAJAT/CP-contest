#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    string x;
    cin>>x;
    string s;
    cin>>s;
    int cnt=0;
    while(n<m)
    {
        n*=2;
        x+=x;
        cnt++;
    }
    if(x.find(s)!=string::npos)
    {
        cout<<cnt<<endl;
        return;
    }
    x+=x;
    cnt++;
    if(x.find(s)!=string::npos)
    {
        cout<<cnt<<endl;
        return;
    }
    cout<<-1<<endl;
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