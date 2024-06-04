#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,f,k;
    cin>>n>>f>>k;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int tmp=a[f-1];
    sort(a.begin(),a.end(),greater<int>());
    int l=0,r=0;
    for(int i=0;i<n;++i)
    {
        if(a[i]==tmp)
        {
            (i<k)?l++:r++;
        }
    }
    if(l>=1 && r==0)
    {
        cout<<"YES"<<endl;
    }
    else if(l==0 && r>=1)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"MAYBE"<<endl;
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