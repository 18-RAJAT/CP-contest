#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    int a[n];
    for(auto& it:a)cin>>it;
    sort(a,a+n);
    int last=a[n-1];
    while(m--)
    {
        char c;
        cin>>c;
        int l,r;
        cin>>l>>r;
        if(c=='+')
        {
            if(l<=last && last<=r)last++;
        }
        else
        {
            if(l<=last && last<=r)last--;
        }
        cout<<last<<" ";
    }
    cout<<endl;
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