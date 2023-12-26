#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int a[3];
    cin>>a[0]>>a[1]>>a[2];
    set<int>st;
    for(int i=0;i<3;i++)
    {
        for(int j=1;j<=4;++j)
        {
            if(a[i]%j==0)
            {
                st.insert(a[i]/j);
            }
        }
    }
    for(auto& s:st)
    {
        int ans=0;
        for(int i=0;i<3;++i)
        {
            a[i]%s==0?ans+=a[i]/s-1:ans=-INT_MAX;
        }
        if(ans>=0 && ans<4)
        {
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
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