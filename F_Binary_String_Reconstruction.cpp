#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(not a or c)
        {
            for(int i=0;i<a;+i)
            {
                cout<<0;
            }
        }
        else
        {
            for(int i=0;i<a+1;+i)
            {
                cout<<0;
            }
        }
        b=(b+1)/2;;
        for(int i=0;i<b;++i)
        {
            cout<<"01";
        }
        if(not c or a)
        {
            for(int i=0;i<c;+i)
            {
                cout<<1;
            }
        }
        else
        {
            for(int i=0;i<c+1;+i)
            {
                cout<<1;
            }
        }
        cout<<"\n";
    }
}