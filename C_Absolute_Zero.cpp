#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
void sol()
{
    int n;
    cin>>n;
    int ans=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        int shift=1<<a[i]%2;
        ans|=shift;
    }
    vector<int>finds;
    if(ans==3)
    {
        cout<<-1<<endl;
        return;
    }
    while(true)
    {
        int res=0;
        for(int i=0;i<n;++i)res=max(a[i],res);
        if(res==0)break;
        finds.push_back((res+1)/2);
        for(int i=0;i<n;++i)a[i]=abs(finds.back()-a[i]);
    }
    cout<<finds.size()<<endl;
    for(int i=0;i<finds.size();++i)
    {
        cout<<finds[i]<<(i+1==finds.size()?"":" ");
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