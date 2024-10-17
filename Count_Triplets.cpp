#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    int ans=0;
    for(int i=0;i<n;++i)
    {
        int l=max(0ll,i-100),r=min(n-1ll,i+100);
        for(int j=l;j<=r;++j)
        {
            int diff=abs((int)a[i]-(int)a[j]),maintain=abs((int)i-(int)j);
            if(diff==maintain) ans+=(maintain+1);
            else if(diff>maintain)
            {
                if((i+j-diff)>=0 && (i+j-diff)%2==0)
                {
                    int j1=(i+j-diff)/2;
                    if(j1>=0 && j1<min(i,j)) ans+=1;
                }
                if((i+j+diff)<2*n && (i+j+diff)%2==0)
                {
                    int j2=(i+j+diff)/2;
                    if(j2>max(i,j) && j2<n) ans+=1;
                }
            }
        }
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