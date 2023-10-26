#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int a[n];
    int swaps[2];
    swaps[0]=0;//even
    swaps[1]=0;//odd
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        if((a[i]&1)^(i&1))//if one is odd and other is even
        {
            swaps[a[i]&1]++;
        }
    }
    if(swaps[0]!=swaps[1] || n<0)
    {
        cout<<"-1\n";
        return;
    }
    else
    {
        cout<<swaps[0]<<'\n';
    }
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