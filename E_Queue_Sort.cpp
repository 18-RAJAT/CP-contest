#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int mn=*min_element(a.begin(),a.end());
    for(int i=0;i<n;++i)
    {
        if(a[i]==mn)
        {
            cout<<(is_sorted(a.begin()+i,a.end())?i:-1)<<endl;
            return;
        }
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