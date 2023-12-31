#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int x,y;
    cin>>x>>y;
    if((x+1<y || y==0) || (x!=0 && y==1))
    {
        cout<<"No"<<endl;
    }
    else
    {
        if(y==x+1)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            ((x-y)&1)?cout<<"Yes":cout<<"No";
        }
    }
}
signed main()
{
    sol();
    return 0;
}