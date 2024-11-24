#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n+1,-1);
    unordered_set<int>st;
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<i;++j)
        {
            if(st.count(j)==0)
            {
                a[i]=j;
                st.insert(j);
                break;
            }
        }
    }
    vector<int>ans;
    int res=0;
    for(int i=1;i<=n;++i)
    {
        int tmp=a[i],x=-1;
        for(int j=res+1;j<=100;++j)
        {
            if(j%i==tmp)
            {
                x=j;
                break;
            }
        }
        ans.push_back(x);
        res=x;
    }
    for(int i=0;i<ans.size();++i)
    {
        cout<<ans[i]<<(i<ans.size()-1?' ':'\n');
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