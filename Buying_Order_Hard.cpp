#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        a[i]=rand();
    }
    int x=0,y=0;
    for(int i=0;i<n;++i)
    {
        int p;
        cin>>p;
        if(p==1)x=max(x+1,y+1);
        else y=x+1;
        cout<<2*(i+1)-max(x,y)<<" ";
    }
    cout<<endl;
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