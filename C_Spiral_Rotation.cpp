#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<vector<char>>a(n,vector<char>(n));
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cin>>a[i][j];
        }
    }
    for(int k=0;k<n/2;++k)
    {
        int L=k,R=n-1-k;
        for(int i=L;i<R;++i)
        {
            int temp=i-L;
            char top=a[L][i];
            a[L][i]=a[R-temp][L];
            a[R-temp][L]=a[R][R-temp];
            a[R][R-temp]=a[i][R];
            a[i][R]=top;
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cout<<a[i][j];
        }
        cout<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}