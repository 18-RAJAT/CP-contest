#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(32);
    for(int i=0;i<31;++i)
    {
        if(n&(1<<i))a[i]=1;
    }
    for(int i=0;i<31;++i)
    {
        if(a[i]==1 && a[i+1]==1)
        {
            int color=i+1;
            for(;color<32 && a[color]==1;)
            {
                a[color]=0,color++;
            }
            a[i]=-1,a[color]=1;
        }
    }
    for(auto i=a.rbegin();i!=a.rend();i=a.rbegin())
    {
        if(*i==0)
        {
            a.pop_back();
        }
        else
        {
            break;
        }
    }
    cout<<a.size()<<endl;
    for(auto& i:a)cout<<i<<" ";
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