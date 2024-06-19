#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int sum=0,odd=INT_MAX,ok=0;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        if(x&1)odd=min(x,odd),ok=1;
        sum+=x;
    }
    sum=(sum&1)?(ok?sum-odd:sum):sum;
    cout<<sum;
}
signed main()
{
    sol();
    return 0;
}