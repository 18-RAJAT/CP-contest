#include<bits/stdc++.h>
using namespace std;
#define int long long
int Xor(int a,int b){return a^b;}
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    int ans=1e18,f=0;
    if(n>1000)
    {
        cout<<-1;
        return;
    }
    for(int i=0;i<n;++i)
    {
        int ok=0;
        for(int j=i;j>=0;--j)
        {
            ok^=a[j];
            int f=0;
            for(int k=i+1;k<n;++k)
            {
                f^=a[k];
                if(f<ok)ans=min(ans,i-j+k-i-1);
            }
        }
    }
    if(ans==1e18)ans=-1;
    cout<<ans;
}
signed main()
{
    sol();
    return 0;
}