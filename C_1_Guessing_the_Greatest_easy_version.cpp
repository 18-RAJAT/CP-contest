#include<bits/stdc++.h>
using namespace std;
#define int long long
int index;
void query(int l,int r)
{
    cout<<"? "<<l<<" "<<r<<endl;
    cin>>index;
}
void sol()
{
    int n;
    cin>>n;
    int l=1,r=n,ans;
    while(l<r)
    {
        query(l,r);
        if(r==l+1)
        {
            if(l==index)ans=r;
            else ans=l;
            break;
        }
        int mid=(l+r)>>1;
        int temp=index;
        if(temp<=mid)
        {
            query(l,mid);
            if(index==temp)r=mid;
            else l=mid;
        }
        else
        {
            query(mid,r);
            if(index==temp)l=mid;
            else r=mid;
        }
    }
    if(l==r)ans=l;
    cout<<"! "<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}