#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000001];
void sol()
{
    int n;
    cin>>n;
    int pos=0,neg=0,zero=0;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        if(a[i]==0)
        {
            ++zero;
        }
        else if(a[i]>0)
        {
            ++pos;
        }
        else
        {
            ++neg;
        }
    }
    if(zero)
    {
        cout<<"0"<<endl;
        return;
    }
    if(neg%2==0)
    {
        // cout<<"0"<<endl;
        cout<<1<<endl;
        cout<<1<<" "<<0<<endl;
        return;
    }
    // else
    // {
    //     cout<<neg-1<<endl;
    //     return;
    // }
    cout<<0<<endl;
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