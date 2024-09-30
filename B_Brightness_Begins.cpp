#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int k;
    cin>>k;
    int Root=sqrt(k),Begin=Root+k;
    if((long long)(sqrt(Begin))>Root)
    {
        Begin++;
    }
    cout<<Begin<<endl;
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