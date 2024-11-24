#include<bits/stdc++.h>
using namespace std;
#define int long long
int calc(int x)
{
    return x*(x+1)/2;
}
bool check(int x,int w,int b)
{
    return (calc(x)<=w+b) && (x<=w || x<=b);
}
void sol()
{
    int w,b;
    cin>>w>>b;
    int left=0,right=1e6;
    int ans=0;
    while(left<=right)
    {
        int mid=left+(right-left)/2;
        (check(mid,w,b))?ans=mid,left=mid+1:right=mid-1;
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