#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k,a,b;
    cin>>n>>k>>a>>b;
    function<int(int,int,int,int)>recur=[&](int n,int k,int a,int b)->int
    {
        if(n<k || k==1)
        {
            return a*(n-1);
        }
        return(n%k==0)?min(a*(n-n/k),b)+recur(n/k,k,a,b):min((n%k),n-1)*a+recur(n-min(n-1,(n%k)),k,a,b);
    };
    cout<<recur(n,k,a,b);
}
signed main()
{
    int t;
    sol();
    return 0;
}