#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int count=0;
    while(true)
    {
        bool flag=true;
        for(int i=1;i<n;++i)
        {
            if(a[i-1]>a[i])
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            break;
        }
        for(int i=1;i<n;++i)
        {
            if(a[i-1]>a[i])
            {
                a[i]*=2;
                ++count;
            }
        }
    }
    cout<<count<<"\n";
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