#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;++i)
    {
        cin>>b[i];
    }
    sort(a.rbegin(),a.rend());
    sort(b.rbegin(),b.rend());
    int i=0,j=0;
    while(i<n)
    {
        if(a[i]<=b[j])
        {
            i++,j++;
        }
        else
        {
            i++;
        }
    }
    cout<<(n-j)<<endl;
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