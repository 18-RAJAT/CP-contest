#include<bits/stdc++.h>
using namespace std;
#define int long long
int query(string q)
{
    cout<<"1 "<<q<<endl;
    cout.flush();
    int res;
    cin>>res;
    return res;
}
void guess(int i,char c)
{
    cout<<"0 "<<i<<" "<<c<<endl;
    cout.flush();
    int res;
    cin>>res;
    if(res==-1)exit(0);
}
void sol()
{
    int n;
    cin>>n;
    int cnt1=query("0");
    if(cnt1>0)
    {
        int m=(n+1)/2;
        guess(m,'0');
    }
    else
    {
        guess(1,'1');
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