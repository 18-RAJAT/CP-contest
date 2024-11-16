#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    array<int,10>arr={0};
    while(n)
    {
        arr[n%10]++;
        n/=10;
    }
    if(arr[1]==1 && arr[2]==2 && arr[3]==3)cout<<"Yes";
    else cout<<"No";
}
signed main()
{
    sol();
    return 0;
}