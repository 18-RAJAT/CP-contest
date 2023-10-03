#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    /*
        Approach:
        Determine the maximum possible value of x.
        Then, iterate through all possible values of x and check if the array can be transformed to the array x^a[i] for all i.
    */
   
    int n;
    cin>>n;
    vector<int>a(n),tmp(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    for(int i=1;i<1024;++i)
    {
        for(int j=0;j<n;++j)
        {
            tmp[j]=a[j]^i;
        }
        sort(tmp.begin(),tmp.end());
        if(tmp==a)
        {
            cout<<i<<endl;
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