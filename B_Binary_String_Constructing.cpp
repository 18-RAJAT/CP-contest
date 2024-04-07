#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int a,b,x;
    cin>>a>>b>>x;
    if(x&1)
    {
        if(a>b)
        {
            for(int i=0;i<x/2;++i)
            {
                cout<<"01";
            }
            for(int i=0;i<a-x/2;++i)
            {
                cout<<"0";
            }
            for(int i=0;i<b-x/2;++i)
            {
                cout<<"1";
            }
        }
        else
        {
            for(int i=0;i<x/2;++i)
            {
                cout<<"10";
            }
            for(int i=0;i<b-x/2;++i)
            {
                cout<<"1";
            }
            for(int i=0;i<a-x/2;++i)
            {
                cout<<"0";
            }
        }
    }
    else
    {
        if(a>b)
        {
            for(int i=0;i<x/2;++i)
            {
                cout<<"01";
            }
            for(int i=0;i<b-x/2;++i)
            {
                cout<<"1";
            }
            for(int i=0;i<a-x/2;++i)
            {
                cout<<"0";
            }
        }
        else
        {
            for(int i=0;i<x/2;++i)
            {
                cout<<"10";
            }
            for(int i=0;i<a-x/2;++i)
            {
                cout<<"0";
            }
            for(int i=0;i<b-x/2;++i)
            {
                cout<<"1";
            }
        }
    }
    cout<<endl;
}
signed main()
{
    sol();
    return 0;
}