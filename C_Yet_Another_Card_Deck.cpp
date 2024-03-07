#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,q;
    cin>>n>>q;
    vector<int>arr(n);
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
    }
    vector<int>ans;
    for(int i=0;i<q;++i)
    {
        int x;
        cin>>x;
        int index=0;
        for(int j=0;j<n;++j)
        {
            if(arr[j]==x)
            {
                ans.push_back(j+1);
                for(int k=j;k>0;--k)
                {
                    swap(arr[k],arr[k-1]);
                }
                break;
            }
        }
    }
    for(int i=0;i<ans.size();++i)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
signed main()
{
    sol();
    return 0;
}