#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    int c=a[0];
    vector<int>b=a;
    sort(b.begin(),b.end());
    int LB=lower_bound(b.begin(),b.end(),c)-b.begin();
    int l,r;
    (LB>=1)?l=(b[LB-1]+c+1)/2:l=1;
    (LB<n-1)?r=(b[LB+1]+c)/2:r=1000000;
    l=max<int>(l,1),r=min<int>(r,1000000);
    cout<<((r<l)?0:r-l+1)<<endl;
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