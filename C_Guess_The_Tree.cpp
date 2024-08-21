#include<bits/stdc++.h>
using namespace std;
#define int long long
int ask(int a,int b)
{
    cout<<"? "<<a<<" "<<b<<endl;
    cout.flush();
    int x;
    cin>>x;
    return x;
}
int nbg(int x)
{
    int y=1,z=ask(x,y);
    while(x!=z)
    {
        y=z,z=ask(x,y);
    }
    return y;
}
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n+1);
    for(int i=2;i<=n;++i)
    {
        a[i]=nbg(i);
    }
    cout<<"!";
    for(int i=2;i<=n;++i)
    {
        cout<<" "<<i<<" "<<a[i];
    }
    cout<<endl;
    cout.flush();
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