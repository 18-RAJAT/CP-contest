#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    // for(int i=0;i<n;++i)
    // {
    //     cin>>a[i];
    // }
    int mn=*min_element(a.begin(),a.end());
    map<int,vector<int>>mp;
    mp.clear();
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        mp[a[i]].emplace_back(i);
    }
    int aux=n;
    int tmp=n+1;
    for(auto&[it,itr]:mp)
    {
        // if(it==mn)
        // {
        //     continue;
        // }
        // int LB=lower_bound(a.begin(),a.end(),it)-a.begin();
        int LB=lower_bound(itr.begin(),itr.end(),tmp)-itr.begin();
        int value=itr[0];
        if(LB>=1)
        {
            LB--;
            n-=LB+1;
            
            // cout<<n;
            aux=min<int>(aux,n+it);
            // tmp=min<int>(tmp,value);
            tmp=itr[0];
        }
        // if(itr.size()==1)
        // {
        //     tmp=itr[0];
        //     break;
        // }
        // else
        // {
        //     tmp=min(tmp,itr[0]);
        // }
    }
    cout<<aux<<endl;
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