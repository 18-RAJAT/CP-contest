#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int a,b;
    cin>>a>>b;
    int cnt=3;
    vector<int>arr(cnt,b);
    arr[0]=a*cnt-b*(cnt-1);
    cout<<cnt<<endl;
    for(int i=0;i<cnt;++i)cout<<arr[i]<<" ";
    cout<<endl;
}
signed main()
{
    sol();
    return 0;
}