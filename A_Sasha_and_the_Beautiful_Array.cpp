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
    sort(array.begin(),array.end());
    int max_beauty=0;
    for(int i=1;i<n;++i)
    {
        max_beauty+=(array[i]-array[i-1]);
    }
    cout<<max_beauty<<endl;
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