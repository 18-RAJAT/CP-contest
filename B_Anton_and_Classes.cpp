#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int n;
    cin>>n;
    int lPos[n],rPos[n];
    int R=INT_MAX,L=INT_MIN;
    for(int i=0;i<n;++i)
    {
        cin>>lPos[i]>>rPos[i];
        R=min<int>(R,rPos[i]);
        L=max<int>(L,lPos[i]);
    }
    int m;
    cin>>m;
    int ans=0;
    for(int i=0;i<m;++i)
    {
        int l,r;
        cin>>l>>r;
        if(l>R)
        {
            ans=max<int>(ans,l-R);
        }
        if(r<L)
        {
            ans=max<int>(ans,L-r);
        }
    }
    cout<<ans<<endl;
    return 0;
}