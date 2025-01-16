#include<bits/stdc++.h>
using namespace std;
#define int long long
int check(deque<int>pos,deque<int>neg,int x)
{
    int s=0,m=0;
    while(!pos.empty() || !neg.empty())
    {
        if(!pos.empty())
        {
            if(s+pos.front()>x)
            {
                if(!neg.empty())s+=neg.front(),m=max(m,s),neg.pop_front(),s=max(0LL,s);
                else return false;
            }
            else s+=pos.front(),m=max(m,s),pos.pop_front();
        }
        else if(!neg.empty())
        {
            s+=neg.front(),m=max(m,s),neg.pop_front(),s=max(0LL,s);
        }
    }
    return m<=x;
}
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int& it:a)cin>>it;
    deque<int>pos,neg;
    for(auto& it:a)
    {
        if(it>=0)pos.push_back(it);
        else neg.push_back(it);
    }
    if(pos.empty())
    {
        cout<<0<<endl;
        return;
    }
    int l=*max_element(pos.begin(),pos.end()),sum=accumulate(pos.begin(),pos.end(),0LL),r=sum,ans=r;
    while(l<=r)
    {
        int mid=(l+r)/2;
        deque<int>p=pos,n=neg;
        ((check(p,n,mid))?(ans=mid,r=mid-1):(l=mid+1));
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