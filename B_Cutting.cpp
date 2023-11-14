#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int odd=0,even=0,ans=0,element=0;
    vector<int>check;
    for(int i=0;i<n-1;++i)
    {
        if(a[i]&1)
        {
            odd++;
        }
        else
        {
            even++;
        }
        if(odd==even)
        {
            check.push_back(abs(a[i]-a[i+1]));
            element=i,odd=0,even=0;
        }
    }
    if(!check.size())
    {
        cout<<"0\n";
        return;
    }
    sort(check.begin(),check.end());
    for(int i=0;i<check.size();++i)
    {
        if(check[i]<=k)
        {
            ans++;
            k-=check[i];
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