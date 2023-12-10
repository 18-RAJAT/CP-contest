#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    int ans=2e18+5;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    if(k>2)
    {
        cout<<"0"<<endl;
        return;
    }
    sort(a.begin(),a.end());
    for(int i=0;i+k<n;++i)
    {
        int diff=abs<int>(a[i]-a[i+1]);
        ans=min(ans,diff);
        if(k==2)
        {
            auto lb=lower_bound(a.begin(),a.end(),diff);
            if(lb==a.end())
            {
                continue;
            }
            if(lb==a.begin())
            {
                ans=min<int>(ans,abs<int>(a[*lb]-diff));
            }
            else
            {
                ans=min<int>(ans,abs<int>(a[*lb]-diff));
                lb--;
                ans=(lb==a.end()?ans:min<int>(ans,abs<int>(a[*lb]-diff)));
            }
        }
    }
    int minimum_ans=*min_element(a.begin(),a.end());
    cout<<min(ans,minimum_ans)<<endl;
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