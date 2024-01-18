#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int a[151];
    fill(a,a+151,0);
    for(int i=0;i<n;++i)
    {
        int x,y;
        cin>>x>>y;
        int curr=s[i]-'0';
        for(int j=0;j<=150;++j)
        {
            if((j-y)%x==0 && j-y>=0)
            {
                //toggle
                curr^=1;
            }
            a[j]+=curr;
        }
    }
    int mx=0;
    for(int i=0;i<=150;++i)
    {
        mx=max<int>(mx,a[i]);
    }
    cout<<mx;
}
signed main()
{
    sol();
    return 0;
}