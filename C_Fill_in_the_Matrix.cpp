#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
void sol()
{
    int n,m;
    cin>>n>>m;
    cout<<((m==1)?0:min(1+n,m))<<endl;//chk with m=1
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            //fill in the matrix
            int mn=min(m-2,i);
            int mx=max(mn,mn+j);
            mx%=m;
            // cout<<mx<<" "<<mn<<endl;
            cout<<mx<<" ";
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