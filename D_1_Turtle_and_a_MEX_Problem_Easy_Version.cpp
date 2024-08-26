#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    int MEX=0,ans=0;
    for(int i=1;i<=n;++i)
    {
        int k,x;
        cin>>k;
        vector<bool>chk(k+10,0);
        for(int j=1;j<=k;++j)
        {
            cin>>x;
            if(x<=k+10)chk[x]=true;
        }
        int count=0;
        for(int j=0;j<=k+10;++j)
        {
            if(chk[j]==0 && count<2)
            {
                MEX=max(MEX,j);
                count++;
            }
        }
    }
    if(MEX<=m)ans=MEX*(MEX+1)+(MEX+1+m)*(m-MEX)/2;
    else ans=(m+1)*MEX;
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