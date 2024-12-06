#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    int ans=0;
    for(int i=0;i<n-1;++i)
    {
        if(a[i]>a[i+1])
        {
            if(ans!=0)
            {
                cout<<-1;
                return;
            }
            ans=i+1;
        }
    }
    if(ans==0)
    {
        cout<<0;
        return;
    }
    if(a[n-1]>a[0])
    {
        cout<<-1;
        return;
    }
    cout<<n-ans;
}
signed main()
{
    sol();
    return 0;
}