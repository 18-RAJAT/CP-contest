#include<bits/stdc++.h>
using namespace std;
#define int long long
bool recur(vector<int>&arr,int R,int L)
{
    int ans=0;
    for(auto& it:arr)
    {
        if(it-R>ans)return false;
        ans=max(ans,it+R);
        if(ans>=L)return true;
    }
    return ans>=L;
}
void sol()
{
    int n,m,L;
    cin>>n>>m>>L;
    vector<int>p(n);
    for(auto&x:p)cin>>x;
    sort(p.begin(),p.end());
    vector<int>l(m);
    for(auto&x:l)cin>>x;
    sort(l.begin(),l.end());
    int left=0,right=m-1,answer=-1;
    while(left<=right)
    {
        int mid=left+(right-left)/2;
        if(recur(p,l[mid],L))
        {
            answer=l[mid];
            right=mid-1;
        }
        else left=mid+1;
    }
    cout<<(~answer?to_string(answer):"-1");
}
signed main()
{
    sol();
    return 0;
}