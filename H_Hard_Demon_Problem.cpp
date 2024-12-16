#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,q;
    cin>>n>>q;
    vector<vector<int>>S(n+1,vector<int>(n+1,0)),Sr(n+1,vector<int>(n+1,0)),Sc(n+1,vector<int>(n+1,0)),V(n,vector<int>(n));
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cin>>V[i][j];
            S[i+1][j+1]=S[i][j+1]+S[i+1][j]-S[i][j]+V[i][j]*(j+1);
            Sr[i+1][j+1]=Sr[i][j+1]+Sr[i+1][j]-Sr[i][j]+V[i][j];
            Sc[i+1][j+1]=Sc[i][j+1]+Sc[i+1][j]-Sc[i][j]+V[i][j]*(i+1);
        }
    }
    while(q--)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        int X=S[x2][y2]-S[x2][y1-1]-S[x1-1][y2]+S[x1-1][y1-1];
        int Y=Sr[x2][y2]-Sr[x2][y1-1]-Sr[x1-1][y2]+Sr[x1-1][y1-1];
        int Z=Sc[x2][y2]-Sc[x2][y1-1]-Sc[x1-1][y2]+Sc[x1-1][y1-1];
        int ans=X-Y*(y1-1+x1*(y2-y1+1))+Z*(y2-y1+1);
        cout<<ans<<" ";
    }
    cout<<endl;
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