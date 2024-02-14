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
    int first=0;
    int last=n-1;
    int init=array[0];
    int final=array[n-1];
    while(array[first]==init)
    {
        first++;
    }
    while(array[last]==final)
    {
        last--;
    }
    //base
    if(n==1)
    {
        cout<<0<<endl;
        return;
    }
    if(init!=final)
    {
        cout<<min<signed>(n-first,last+1)<<endl;
        return;
    }
    cout<<max<signed>(0LL,last-first+1)<<endl;
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