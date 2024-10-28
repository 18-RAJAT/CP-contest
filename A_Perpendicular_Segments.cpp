#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int x,y,k;
    cin>>x>>y>>k;
    if(x>=k && y>=k)
    {
        cout<<"0 0 "<<k<<" 0\n0 0 0 "<<k<<endl;
    }
    else
    {
        // int seg=(int)(sqrt(k*2))+1;
        int seg=(int)((k/sqrt(2))+1);
        if(x>=seg && y>=seg)
        {
            cout<<"0 0 "<<seg<<" "<<seg<<endl;
            cout<<"0 "<<seg<<" "<<seg<<" 0\n";
        }
        else
        {
            cout<<"0 0 "<<x<<" "<<y<<endl;
            cout<<"0 "<<y<<" "<<x<<" 0\n";
        }
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