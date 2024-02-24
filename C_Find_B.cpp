#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,q;
    cin>>n>>q;
    vector<int>c(n);
    for(int i=0;i<n;++i)
    {
        cin>>c[i];
    }
    vector<int>check(n+1);
    for(int i=0;i<n;++i)
    {
        check[i+1]=check[i]+c[i];
    }
    vector<int>res(n);
    for(int i=0;i<n;++i)
    {
        if(c[i]==1)
        {
            res[i]=1;
        }
    }
    vector<int>check_res(n+1);
    for(int i=0;i<n;++i)
    {
        check_res[i+1]=check_res[i]+res[i];
    }
    for(int i=0;i<q;++i)
    {
        int l,r;
        cin>>l>>r;
        if(l==r)
        {
            cout<<"NO"<<endl;
            continue;
        }
        l--;
        //now we have to find the number of 1s in the range l to r and the number of 1s in the range l to r-1
        int ones=check[r]-check[l]-abs(l-r);//r to l
        // cout<<"check[r]: "<<check[r]<<" check[l]: "<<check[l]<<" r-l: "<<r-l<<endl;
        int ones_res=check_res[r]-check_res[l];
        cout<<(ones_res<=ones?"YES":"NO")<<endl;
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