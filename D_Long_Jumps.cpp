#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,l,x,y;
    cin>>n>>l>>x>>y;
    array<int,100005>pos;
    set<int>pts;
    for(int i=0;i<n;++i)
    {
        cin>>pos[i];
        pts.insert(pos[i]);
    }
    int X=0,Y=0;
    for(int i=0;i<n;++i)
    {
        if(pts.count(pos[i]+x))X=1;
        if(pts.count(pos[i]+y))Y=1;
    }
    if(X && Y)cout<<0<<endl;
    else if(X)cout<<1<<endl<<y<<endl;
    else if(Y)cout<<1<<endl<<x<<endl;
    else
    {
        int ok=0,f;
        vector<int>dx={-1,-1,1,1},dy={-1,1,-1,1};
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<4;++j)
            {
                int Npos=pos[i]+dx[j]*x;
                if(Npos>=0 && Npos<=l && Npos)
                {
                    if(pts.count(Npos+dy[j]*y))
                    {
                        f=pos[i]+dx[j]*x;
                        ok=1;
                        break;
                    }
                }
            }
            if(ok)break;
        }
        cout<<(ok?1:2)<<endl<<(ok?f:x)<<" "<<(ok?y:y)<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}