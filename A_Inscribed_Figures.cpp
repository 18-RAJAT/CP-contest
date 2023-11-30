#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=1;i<n;++i)
    {
        if(a[i-1]==2 && a[i]==3)
        {
            cout<<"Infinite"<<endl;
            return;
        }
        if(a[i-1]==3 && a[i]==2)
        {
            cout<<"Infinite"<<endl;
            return;
        }
    }
    int cnt=0;
    for(int i=1;i<n;++i)
    {
        if(a[i-1]==1 && a[i]==2)
        {
            cnt+=3;
        }
        if(a[i-1]==2 && a[i]==1)
        {
            cnt+=3;
        }
        if(a[i-1]==1 && a[i]==3)
        {
            cnt+=4;
        }
        if(a[i-1]==3 && a[i]==1)
        {
            cnt+=4;
        }
    }
    for(int i=2;i<n;++i)
    {
        if(a[i-2]==3 && a[i-1]==1 && a[i]==2)
        {
            cnt--;
        }
    }
    cout<<"Finite"<<endl;
    cout<<cnt<<endl;
}
signed main()
{
    sol();
    return 0;
}