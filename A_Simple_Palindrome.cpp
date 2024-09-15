#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    map<int,char> v={{0,'a'},{1,'e'},{2,'i'},{3,'o'},{4,'u'}};
    int check=n/5,ans=n%5;
    for(int i=0;i<5;++i)
    {
        for(int j=1;j<=check;++j)
        {
            cout<<v[i];
        }
        if(ans)
        {
            ans--;
            cout<<v[i];
        }
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