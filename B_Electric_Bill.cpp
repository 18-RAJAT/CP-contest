#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int e=0,mx=0,id=-1;
    for(int i=0;i<n;++i)
    {
        int p,t;
        cin>>p>>t;
        int tmp=p*t;
        e+=tmp;
        if(tmp>mx)
        {
            mx=tmp,id=i+1;
        }
    }
    cout<<e<<endl;
    cout<<id<<" "<<mx<<endl;
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