#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005];
void sol()
{
    cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];
    sort(a,a+n);
    int ok=0,tmp=0;
    for(int i=n-1;i>0;--i)
    {
        if(a[i]==a[i-1])
        {
            ok=1,tmp=a[i],a[i]=-2e9,a[i-1]=2*-2e9;
            break;
        }
    }
    if(!ok)
    {
        cout<<-1<<endl;
        return;
    }
    sort(a,a+n);
    for(int i=n-1;i>0;--i)
    {
        if(a[i]-a[i-1]<tmp*2)
        {
            cout<<tmp<<" "<<tmp<<" "<<a[i]<<" "<<a[i-1]<<endl;
            return;
        }
    }
    cout<<-1<<endl;
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