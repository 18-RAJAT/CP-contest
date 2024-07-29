#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<1<<endl;
        cout<<1<<endl;
    }
    else if(n==2)
    {
        cout<<2<<endl;
        cout<<"1 "<<"2"<<endl;
    }
    else if(n==3)
    {
        cout<<2<<endl;
        cout<<"1 "<<"2 "<<"2"<<endl;
    }
    else if(n==4)
    {
        cout<<3<<endl;
        cout<<"1 "<<"2 "<<"2 "<<"3"<<endl;
    }
    else if(n==5)
    {
        cout<<3<<endl;
        cout<<"1 "<<"2 "<<"2 "<<"3 "<<"3"<<endl;
    }
    else
    {
        cout<<4<<endl;
        for(int i=0;i<n;++i)
        {
            if((i+1)%4==0)cout<<4<<" ";
            else cout<<(i+1)%4<<" ";
        }
        cout<<endl;
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