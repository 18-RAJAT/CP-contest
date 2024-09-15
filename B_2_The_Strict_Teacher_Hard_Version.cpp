#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m,q;
    cin>>n>>m>>q;
    set<int>st{0,n+1};
    for(int i=0;i<m;++i)
    {
        int x;
        cin>>x;
        st.insert(x);
    }
    for(int i=0;i<q;++i)
    {
        int x;
        cin>>x;
        int LB=*--st.lower_bound(x);
        int UB=*st.lower_bound(x);
        if(LB==0)
        {
            cout<<UB-1<<endl;
            continue;
        }

        if(UB==n+1)
        {
            cout<<n-LB<<endl;
            continue;
        }
        cout<<(UB-LB)/2<<endl;
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