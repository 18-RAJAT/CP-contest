#include<bits/stdc++.h>
using namespace std;
#define int long long
int query(int a,int b)
{
    cout<<"? "<<a<<" "<<b<<endl;
    int x;
    cin>>x;
    return x;
}
void sol()
{
    int l=2,r=1000;
    while(l<r)
    {
        int m1=l+(r-l)/3,m2=l+(r-l)/3;
        int take=query(m1,m2);
        if(take==m1*m2)l=m2+1;
        else if(take==(m1+1)*(m2+1))r=m1;
        else l=m1+1,r=m2;
    }
    cout<<"! "<<l<<endl;
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