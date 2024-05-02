#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    string a,b;
    cin>>a>>b;
    int i=0,j=0;
    while(i<n && j<m)
    {
        if(a[i]==b[j])
        {
            i++;
        }
        j++;
    }
    cout<<i<<endl;
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