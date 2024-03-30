#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,s;
    cin>>n>>s;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    double D1=1,D2=1,P1=0,P2=s,Ans=0;
    int Left=0,Right=n-1;
    while(Left<=Right)
    {
        double Res[2]={(a[Left]-P1)/D1,(P2-a[Right])/D2};
        P1+=min(Res[0],Res[1])*D1;
        P2-=min(Res[0],Res[1])*D2;
        Ans+=min(Res[0],Res[1]);
        if(Res[0]<Res[1])`
        {
            D1++;
            Left++;
        }
        else
        {
            D2++;
            Right--;
        }
    }
    Ans+=(P2-P1)/(D1+D2);
    cout<<fixed<<setprecision(8)<<Ans<<endl;
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