#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>array(n);
    for(int i=0;i<n;++i)
    {
        cin>>array[i];
    }
    vector<int>res(n,n);
    for(int i=n-2;~i;--i)
    {
        (array[i]==array[i+1])?res[i]=res[i+1]:res[i]=i+1;
    }
    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        (res[l-1]<=r-1)?cout<<l<<" "<<res[l-1]+1<<endl:cout<<-1<<" "<<-1<<endl;
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