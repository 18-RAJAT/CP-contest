#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,q;
    cin>>n>>q;
    vector<int>a(n),b(q);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<q;++i)
    {
        cin>>b[i];
    }
    vector<int>sum(n);
    sum[0]=a[0];
    for(int i=1;i<n;++i)
    {
        sum[i]=sum[i-1]+a[i];
    }
    int total=sum[n-1];
    int arrow=0;
    for(int i=0;i<q;++i)
    {
        arrow+=b[i];
        if(total<=arrow)
        {
            cout<<n<<endl;
            arrow=0;
        }
        else
        {
            int idx=upper_bound(sum.begin(),sum.end(),arrow)-sum.begin();
            cout<<n-idx<<endl;
        }
    }
    assert(n==sum.size());
}
signed main()
{
    sol();
    return 0;
}