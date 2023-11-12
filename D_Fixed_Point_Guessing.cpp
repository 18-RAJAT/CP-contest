#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int low=1,high=n;
    while(low<high)
    {
        int mid=low+(high-low)/2;
        auto ask=[&]()->void
        {
            cout<<"? "<<low<<" "<<mid<<endl;
        };
        ask();
        int count=0;
        int q=mid-low+1;
        for(int i=0;i<q;++i)
        {
            int x;
            cin>>x;
            assert(~x);
            if(low<=x && x<=mid)
            {
                count++;
            }
        }
        if(count&1)
        {
            high=mid;
        }
        else
        {
            low=mid+1;
        }
    }
    cout<<"! "<<low<<endl;
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