#include<bits/stdc++.h>
using namespace std;
#define int long long
int BinarySearchAns(int u,int n,int x)
{
    int s=0,c=u,move=0;
    while(move<n && c>=1)
    {
        if(s>x-c)
        {
            s=x+1;
            break;
        }
        s+=c,c/=2,move++;
    }
    return s;
}
void sol()
{
    int x,n;
    cin>>x>>n;
    int l=1,r=1000000000000000000LL,ans=-1;
    while(l<=r)
    {
        int m=l+(r-l)/2;
        int s=BinarySearchAns(m,n,x);
        if(s==x)
        {
            ans=m;
            break;
        }
        else if(s<x)l=m+1;
        else r=m-1;
    }
    cout<<(~ans?to_string(ans):"-1")<<endl;
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