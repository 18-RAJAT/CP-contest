#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Mod=1000000007;
const int N=100005;
void sol()
{
    vector<int>arr(N,1);
    for(int i=1;i<N;++i)
    {
        arr[i]=arr[i-1]*2%Mod;
    }
    int n;
    cin>>n;
    vector<int>A(n),B(n);
    for(int i=0;i<n;++i)
    {
        cin>>A[i];
    }
    for(int i=0;i<n;++i)
    {
        cin>>B[i];
    }
    for(int i=0;i<n;++i)
    {
        cout<<arr[B[i]]%Mod<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}