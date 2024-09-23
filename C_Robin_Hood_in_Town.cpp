#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    if(n<=2)
    {
        cout<<-1<<endl;
        return;
    }
    nth_element(a.begin(),a.begin()+n/2,a.end());
    int MedianWealth=2*a[n/2],TotalWealth=accumulate(a.begin(),a.end(),0LL);
    int RequiredWealth=MedianWealth*n;
    cout<<max(RequiredWealth-TotalWealth+1LL,0LL)<<endl;
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