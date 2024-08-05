#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    vector<int>take(k),leave(k);
    int ok=0;
    for(int i=0;i<n;++i)
    {
        int m=(a[n-1]-a[i]+k-1)/k;
        int y=a[i]+k*m-a[n-1];
        assert(y>=0 && y<k);
        (m&1)?leave[y]++,ok++:take[y]++;
    }
    for(int i=0;i<k;++i)
    {
        while(leave[i]--)ok--;
        while(take[i]--)ok++;
        if(ok==n)
        {
            cout<<i+a[n-1]<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}
signed main()
{
    int y;
    cin>>y;
    while(y--)
    {
        sol();
    }
    return 0;
}