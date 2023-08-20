#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a;
    int ert=n*(n-1)/2;
    for(int i=1;i<=ert;i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    int pos=0;
    for(int i=n-1;i>=1;i--)
    {
        cout<<a[pos]<<" ";
        pos+=i;
    }
    cout<<a.back()<<"\n";
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