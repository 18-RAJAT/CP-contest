#include<bits/stdc++.h>
using namespace std;
#define int long long

int recur(int x,int y,int k)
{
    if(x==1)return (x+k%(y-1));
    int ans=(x+y-1)/y*y,conj=ans-x;
    if(conj<=k)return recur(ans/y,y,k-conj);
    return x+k;
}
void sol()
{
    int x,y,k;
    cin>>x>>y>>k;
    if(x%y==0)x++,k--;
    cout<<recur(x,y,k)<<endl;    
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