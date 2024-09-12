#include<bits/stdc++.h>
using namespace std;
#define int long long

int findMinValue(int a,int b,int k)
{
    if(k==1)return 0;
    int low=0,high=1e18,ans=0;
    while(low<=high)
    {
        int mid=(low+high)/2;
        int count=mid/b+((a<=mid)?(mid-a)/b+1:0);
        (k<=1+count)?(ans=mid,high=mid-1):(low=mid+1);
    }
    return ans;
}
void sol()
{
    int a,b,k;
    cin>>a>>b>>k;
    map<int,int>sequence;
    sequence[0]=0;
    sequence[1]=a;
    sequence[2]=b;
    for(int i=3;i<13;++i)
    {
        sequence[i]=sequence[i-1]+sequence[i-2]+sequence[i-3];
    }
    cout<<findMinValue(a,b,k)<<endl;
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