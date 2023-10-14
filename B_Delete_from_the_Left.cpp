#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string a,b;
    cin>>a>>b;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int cnt=0;
    while(a!=b)
    {
        if(a.size()>b.size())
        {
            a.pop_back();
        }
        else
        {
            b.pop_back();
        }
        cnt++;
    }
    cout<<cnt;
}
signed main()
{
    sol();
    return 0;
}