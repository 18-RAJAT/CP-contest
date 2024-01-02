#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,x0,y0;
    cin>>n>>x0>>y0;
    set<double>st;
    for(int i=0;i<n;++i)
    {
        int x,y;
        cin>>x>>y;
        if(x==x0)
        {
            st.insert(INT_MAX);
        }
        else
        {
            double slope=(double)(y-y0)/(x-x0);
            st.insert(slope);
        }
    }
    cout<<st.size()<<endl;
}
signed main()
{
    sol();
    return 0;
}