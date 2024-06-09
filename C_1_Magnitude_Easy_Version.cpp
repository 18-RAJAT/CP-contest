#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }   
    int mag1=0,mag2=0,mag3=0,mag4=0;
    for(int i=0;i<n;++i)
    {
        int diff1=abs(mag1+a[i]),diff2=abs(mag2+a[i]);
        mag3=min(min(min(mag1+a[i],mag2+a[i]),diff1),diff2);
        mag4=max(max(max(mag1+a[i],mag2+a[i]),diff1),diff2);
        mag1=mag3,mag2=mag4;
    }
    cout<<abs(mag2)<<endl;
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