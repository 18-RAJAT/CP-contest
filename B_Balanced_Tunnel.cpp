#include<bits/stdc++.h>
using namespace std;
#define INF 1000000000
int main()
{
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    for(auto&it:a)cin>>it;
    for(auto&it:b)cin>>it;
    vector<int>chk(n);
    for(int i=0;i<n;++i)
    {
        chk[a[i]-1]=i;
    }
    int ans(0),curr(INF);
    for(int i=n-1;i>=0;--i)
    {
        if(chk[b[i]-1]>curr)
        {
            ++ans;
        }
        curr=min<int>(curr,chk[b[i]-1]);
    }
    cout<<ans<<"\n";
}