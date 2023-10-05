#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int a[n];
    vector<int>neg;
    int prod=1;
    int mn=INT_MAX;
    int negative=-1;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        if(a[i]>=0)
        {
            a[i]=-a[i]-1;//getting the negative of the number
        }
        // prod*=a[i];//product of all the numbers because if there is no negative number then we have to make one number negative
        if(mn>a[i])
        {
            negative=i;
            mn=a[i];
        }
    }
    if(n&1)
    {
        a[negative]=-a[negative]-1;
        for(int i=0;i<n;++i)
        {
            cout<<a[i]<<" ";
        }
    }
    else
    {
        for(int i=0;i<n;++i)
        {
            cout<<a[i]<<" ";
        }
    }
}
signed main()
{
    sol();
    return 0;
}