#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int x,y;
    cin>>x>>y;
    int large=max(x,y);
    int small=min(x,y);
    int option1=max<int>(0,small-(large/2));
    int option2=max<int>(0,2*small-large);
    cout<<min(option1,option2)<<endl;
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