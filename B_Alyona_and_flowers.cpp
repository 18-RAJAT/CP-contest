#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<int>a,b;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    int l,r;
    for(int i=0;i<m;++i)
    {
        cin>>l>>r;
        int sum=0;
        for(int j=l-1;j<r;++j)
        {
            sum+=a[j];
        }
        b.push_back(sum);
    }
    sort(b.begin(),b.end(),greater<int>());
    int ans=0;
    for(int i=0;i<b.size();++i)
    {
        if(b[i]>0)
        {
            ans+=b[i];
        }
        else
        {
            break;
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}