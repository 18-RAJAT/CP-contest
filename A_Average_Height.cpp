#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>odd,even,a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        (a[i]&1)?odd.push_back(a[i]):even.push_back(a[i]);
    }
    for(int i=0;i<odd.size();++i)
    {
        cout<<odd[i]<<' ';
    }
    for(int i=0;i<even.size();++i)
    {
        cout<<even[i]<<' ';
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