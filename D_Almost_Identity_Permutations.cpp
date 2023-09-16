#include<bits/stdc++.h>
using namespace std;
#define int long long
int arrangement(int n)
{
    if(n==0)
    {
        return 1;
    }
    if(n==1)
    {
        return 0;
    }
    return (n-1)*(arrangement(n-1)+arrangement(n-2));//arrangement(n-1) is for the case when the last element is not in its correct position and arrangement(n-2) is for the case when the last element is in its correct position
}
int NCR(int n,int r)
{
    int res=1;
    for(int i=1;i<=r;++i)
    {
        res*=(n-i+1);
        res/=i;
    }
    return res;
}
void sol()
{
    int n,k;
    cin>>n>>k;
    int ans=0;
    for(int i=0;i<k+1;++i)
    {
        ans+=NCR(n,i)*arrangement(i);
    }
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}