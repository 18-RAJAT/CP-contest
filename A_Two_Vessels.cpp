#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int a,b,c;
    cin>>a>>b>>c;
    int diff=abs<int>(a-b);//4
    int ans=diff+c-1;//4+2-1=5
    int ans1=ans/c+1;//5/2+1=3
    // int ans2=ans/c;//5/2=2
    int ans2=ans1/2;//5/2=2
    // cout<<min<int>(ans1,ans2)*c<<endl;
    cout<<ans2<<endl;
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