#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    if(n<7)
    {
        cout<<"0"<<endl;
        return;
    }
    string str=s+s;
    vector<int>p;
    for(int i=0;i+6<2*n;++i)
    {
        if(str[i]=='n' && str[i+1]=='a' && str[i+2]=='n' && str[i+3]=='j' && str[i+4]=='i' && str[i+5]=='n' && str[i+6]=='g')
        {
            p.push_back(i);
        }
    }
    int mxi=min(k,n-1);
    int L=0,R=0;
    int m=p.size(),ans=0;
    for(int d=0;d<=mxi;++d)
    {
        while(L<m && p[L]<d)L++;
        while(R<m && p[R]<=d+n-7)R++;
        ans=max(ans,R-L);
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