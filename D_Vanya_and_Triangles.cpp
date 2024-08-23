#include<bits/stdc++.h>
using namespace std;
#define int long long
struct st
{
    int x,y;
};
st arr[2005];
tuple<int,int,int>check(int a,int b)
{
    int G=__gcd(a,b);
    a/=G,b/=G;
    return make_tuple(a,b,0);
}
void sol()
{
    int n;
    cin>>n;
    int ans=1LL*n*(n-1)*(n-2)/6;
    for(int i=1;i<=n;++i)
    {
        cin>>arr[i].x>>arr[i].y;
        map<tuple<int,int,int>,int>count;
        for(int j=1;j<i;++j)
        {
            int a=arr[j].x-arr[i].x;
            int b=arr[j].y-arr[i].y;
            tuple<int,int,int>key=check(a,b);
            count[key]++;
        }
        for(map<tuple<int,int,int>,int>::iterator it=count.begin();it!=count.end();++it)
        {
            ans-=it->second*(it->second-1)/2;
        }
    }
    cout<<ans;
}
signed main()
{
    sol();
    return 0;
}