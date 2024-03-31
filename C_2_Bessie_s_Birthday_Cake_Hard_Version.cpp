#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N];
void sol()
{
    int n,x,y;
    cin>>n>>x>>y;
    for(int i=1;i<=x;++i)
    {
        cin>>a[i];
    }
    sort(a+1,a+x+1);
    a[0]=a[x]-n;
    int Last=n-2;
    vector<int>Odd,Even;
    Odd.clear();
    Even.clear();
    for(int i=1;i<=x;++i)
    {
        int diff=a[i]-a[i-1]-1;
        (diff&1?Odd:Even).push_back(diff);
    }
    sort(Odd.begin(),Odd.end());
    sort(Even.begin(),Even.end());
    for(int i=0;i<Odd.size();++i)
    {
        if(Odd[i]/2<=y)
        {
            y-=Odd[i]/2;
            continue;
        }
        Last-=Odd[i]-2*y;
        y=0;
    }
    for(int i=0;i<Even.size();++i)
    {
        if(Even[i]/2<=y)
        {
            y-=Even[i]/2;
            continue;
        }
        Last-=Even[i]-2*y;
        y=0;
    }
    cout<<Last<<endl;
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