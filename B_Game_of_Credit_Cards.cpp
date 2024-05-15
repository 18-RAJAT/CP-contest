#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    int a[n],b[n];
    for(int i=0;i<n;++i)
    {
        a[i]=s[i]-'0';
        b[i]=t[i]-'0';
    }
    sort(a,a+n);
    sort(b,b+n);
    int ans1=0,ans2=0;
    int i=0,j=0;
    for(int i=0,j=0;i<n && j<n;)
    {
        (a[i]<b[j])?ans1++,i++,j++:j++;
    }
    for(int i=0,j=0;i<n && j<n;)
    {
        (a[i]<=b[j])?ans2++,i++,j++:j++;
    }
    cout<<n-ans2<<endl<<ans1<<endl;
}
signed main()
{
    sol();
    return 0;
}