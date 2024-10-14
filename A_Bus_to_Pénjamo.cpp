#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,r;
    cin>>n>>r;
    int row=0,next=0;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        row+=x;
        r-=x/2;
        next+=(x%2);
    }
    for(int i=0;i<=next;++i)
    {
        int s=next-2*i;
        if(i+s<=r && s>=0)
        {
            cout<<row-2*i<<endl;
            return;
        }
    }
}
signed main()
{
    int row;
    cin>>row;
    while(row--)
    {
        sol();
    }
    return 0;
}