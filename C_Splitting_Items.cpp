#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(auto& i:a)cin>>i;
    sort(a.begin(),a.end(),greater<int>());
    for(int i=0;i<n;++i)
    {
        int first=0,last=n-1;
        if(k==0 || last==i){break;}
        int item=min(k,a[i]-a[i+1]);
        a[i+1]+=item,k-=item,i++;
    }
    int A=0,B=0;
    for(int i=0;i<n;++i)
    {
        (i&1)?B+=a[i]:A+=a[i];
    }
    int diff=abs<int>(A-B);
    cout<<diff<<endl;
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