#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>permutation(n);
    for(int i=0;i<n;++i)permutation[i]=i+1;
    for(int i=0;i<n;++i)cout<<permutation[i]<<" ";
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