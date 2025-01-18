#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(auto& it:a)cin>>it;
    auto count=[&](int n)
    {
        return ((n+1)/2)*((n+2)/2);
    };
    int odd=count(n);
    vector<vector<int>>ar(11,vector<int>(n+1,0)),br(11,vector<int>(n+1,0));
    for(int x=1;x<=10;++x)
    {
        for(int i=1;i<=n;++i)
        {
            ar[x][i]=ar[x][i-1]+(a[i-1]<x?1:0);
            br[x][i]=br[x][i-1]+(a[i-1]==x?1:0);
        }
    }
    int even=0;
    for(int x=1;x<=10;++x)
    {
        for(int l=2;l<=n;l+=2)
        {
            int k=l/2;
            for(int j=l;j<=n;++j)
            {
                int i=j-l+1,ok1=ar[x][j]-ar[x][i-1],ok2=br[x][j]-br[x][i-1];
                if((x==1 || x==10) && (ok2>=k+1) && ok1==k)even++;
                else if(ok1<=k-1 && (ok1+ok2)>=k+1)even++;
            }
        }
    }
    cout<<odd+even<<endl;
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