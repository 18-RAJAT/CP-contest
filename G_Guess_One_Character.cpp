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
void guess(int i,int  j)
{
    cout<<"0 "<<i<<" "<<j<<endl;
    cout.flush();
    int res;
    cin>>res;
    return;
}
void sol()
{
    int n;
    cin>>n;
    if(n==1)
    {
        int cnt0=query("0");
        if(cnt0==0)guess(1,1);
        else guess(1,0);
    }
    int z=query("0"),zz=query("00"),zo=query("01");
    if(z==zz+zo)guess(n,1);
    else guess(n,0);
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