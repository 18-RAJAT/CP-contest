#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int e=0,o=0;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        (x%2==0)?e++:o++;
    }
    if(e==0 && o&1)cout<<o;
    else if(e!=0 && o&1)cout<<o;
    else cout<<e;
}
signed main()
{
    sol();
    return 0;
}