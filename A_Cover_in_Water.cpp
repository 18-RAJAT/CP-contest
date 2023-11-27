#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    s+="#";
    if(s.find("...")!=string::npos)
    {
        cout<<"2"<<endl;
    }
    else
    {
        cout<<count(s.begin(),s.end(),'.')<<endl;
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