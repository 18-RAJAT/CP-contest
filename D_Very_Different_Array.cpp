#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<int>a(n),b(m);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<m;++i)
    {
        cin>>b[i];
    }
    auto greater=[](int a,int b)->bool
    {
        return a>b?true:false;
    };
    sort(a.begin(),a.end(),greater);
    sort(b.begin(),b.end());//,greater);
    int ans=0;
    int last=n-1;
    for(int i=0;i<n;++i)
    {
        ans+=abs<int>(a[i]-b[i]);
    }
    int diff_array=ans;
    for(int i=0;i<n;++i)
    {
        int nth=n-i-1,mth=m-i-1;
        // cout<<"nth: "<<nth<<" mth: "<<mth<<endl;
        //find the difference between the current and the next element in the array
        diff_array=diff_array-abs<int>(a[nth]-b[nth])+abs<int>(b[mth]-a[last]);
        // cout<<"diff_array: "<<diff_array<<endl;
        ans=max<int>(ans,diff_array);
        last--;//prev move
    }
    cout<<ans<<endl;
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