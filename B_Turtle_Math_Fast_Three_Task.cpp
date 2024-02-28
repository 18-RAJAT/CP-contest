#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int sum=0;
    vector<array<int,3>>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i][0];
        sum+=a[i][0];
        a[i][1]=a[i][0]%3;
        a[i][2]=a[i][0]%3;
    }
    if(sum%3==0)cout<<0<<endl;
    else if(sum%3==2)
    {
        for(int i=0;i<n;++i)
        {
            if(a[i][1]==2)
            {
                cout<<1<<endl;
                return;
            }
        }
        cout<<(a.size()>=2?1:-1)<<endl;
    }
    else
    {
        for(int i=0;i<n;++i)
        {
            if(a[i][1]==1)
            {
                cout<<1<<endl;
                return;
            }
        }
        cout<<(a.size()>=2?2:-1)<<endl;
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