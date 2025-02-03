#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    k=n-k+1;
    if(k==1)
    {
        int cnt=1;
        for(int i=0;i<n;++i)
        {
            if(i&1)
            {
                if(cnt!=a[i])
                {
                    cout<<cnt<<endl;
                    return;
                }
                cnt++;
            }
        }
        cout<<cnt<<endl;
        return;
    }
    else
    {
        int i=0,j=1;
        while(i<k)
        {
            if(a[j]!=1)
            {
                cout<<1<<endl;
                return;
            }
            i++,j++;
        }
        cout<<2<<endl;
        return;
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