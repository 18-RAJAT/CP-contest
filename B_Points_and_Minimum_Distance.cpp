#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;n*=2;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int ans=0;
    function<int(int,int,int,int)>f=[&](int x1,int y1,int x2,int y2)->int
    {
        return (abs(x1-x2)+abs(y1-y2));
    };
    //check for n=2
    for(int i=0;i<(n/2-1);++i)
    {
        int x1=a[i];
        int y1=a[n-i-1];
        int x2=a[i+1];
        int y2=a[n-i-2];
        ans+=f(x1,y1,x2,y2);
    }
    cout<<ans<<endl;
    //print the answer
    for(int i=0;i<(n/2);++i)
    {
        int x1=a[i];
        int y1=a[n-i-1];
        int x2=a[i+1];
        int y2=a[n-i-2];
        cout<<x1<<" "<<y1<<endl;
    }
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