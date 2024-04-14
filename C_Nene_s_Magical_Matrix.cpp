#include<bits/stdc++.h>
using namespace std;
#define int long long
struct matrix
{
    int mat,idx;
};
void sol()
{
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<1<<" "<<1<<endl<<"1 1 1"<<endl;
        return;
    }
    if(n==2)
    {
        cout<<"7 3"<<endl<<"1 1 2 1"<<endl<<"1 2 2 1"<<endl<<"2 2 2 1"<<endl;
        return;
    }
    int ans=0;
    vector<int>permutation(n);
    iota(permutation.begin(),permutation.end(),1);
    reverse(permutation.begin(),permutation.end());
    vector<matrix>res;
    int state=0;
    for(int i=0;i<n;++i)
    {
        res.push_back({2,i});
    }
    if(n&1)
    {
        int Temp=(n+1)/2-1;
        for(int i=Temp;i>=1;--i)
        {
            res.push_back({1,i});
        }
    }
    else
    {
        int Temp=(n+1)/2;
        for(int i=Temp;i>=1;--i)
        {
            res.push_back({1,i});
        }
    }
    res.push_back({1,2});
    state=res.size();
    state=2*n-state;
    int q=n;
    while(state--)
    {
        res.push_back({2,q--});
    }
    ans=0;
    for(int i=n;i>=1;--i)
    {
        ans+=(2*i-1)*i;
    }
    cout<<ans<<" "<<res.size()<<endl;
    for(int i=0;i<res.size();++i)
    {
        cout<<res[i].mat<<" "<<res[i].idx<<" ";
        for(int j=0;j<n;++j)
        {
            cout<<permutation[j]<<" ";
        }
        cout<<endl;
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