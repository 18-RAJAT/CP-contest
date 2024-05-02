#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int recur(int l,int r,char ch)
{
    if(l==r)
    {
        return (s[l]==ch)?0:1;
    }
    int mid=l+(r-l)/2;
    return min((r-l+1)/2-count(s.begin()+l,s.begin()+mid+1,ch)+recur(mid+1,r,ch+1),(r-l+1)/2-count(s.begin()+mid+1,s.begin()+r+1,ch)+recur(l,mid,ch+1));
}
void sol()
{
    int n;
    cin>>n>>s;
    cout<<recur(0,n-1,'a')<<endl;
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