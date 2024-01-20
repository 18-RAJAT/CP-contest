#include<bits/stdc++.h>
using namespace std;
#define int long long
int XN[1000005],YN[1000005];
void sol()
{
    int n,m;
    cin>>n>>m;
    int files=0;
    int x;
    int sum=0;
    for(int i=0;i<n;++i)
    {
        cin>>x;
        sum+=x;
        XN[sum]++;
    }
    sum=0;
    for(int i=0;i<m;++i)
    {
        cin>>x;
        sum+=x;
        YN[sum]++;
    }
    // for(int i=1;i<=sum;++i)
    // {
    //     cout<<"XN["<<i<<"]="<<XN[i]<<" ";
    //     cout<<"YN["<<i<<"]="<<YN[i]<<endl;
    // }
    for(int i=1;i<=sum;++i)
    {
        if(XN[i]==YN[i] && XN[i]==1 && YN[i]==1 && i!=sum)
        {
            files++;
        }
    }
    cout<<1+files<<endl;
}
signed main()
{
    sol();
    return 0;
}