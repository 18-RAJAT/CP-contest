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
    int m=2*n;
    int maxi=*max_element(a.begin(),a.end());
    vector<int>balanced(m+10),minimized(m+10);
    int half=n/2;
    for(int i=0;i<n;++i)
    {
        int temp=maxi-a[i];
        balanced[i+2]-=temp,balanced[i+half*2+2]+=temp;
        minimized[i]+=half*temp;
        int calc=i+(half-1)*2+3;
        balanced[i+3]+=temp,balanced[i+(half-1)*2+3]-=temp;
        minimized[calc]-=(half-1)*temp;
    }
    for(int i=0;i<m;++i)
    {
        if(i>1)
        {
            balanced[i]+=balanced[i-2];
            minimized[i]+=minimized[i-2]+balanced[i];
        }
    }
    for(int i=0;i<n;++i)
    {
        cout<<minimized[i]+minimized[i+n]<<" \n"[i==n-1];
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