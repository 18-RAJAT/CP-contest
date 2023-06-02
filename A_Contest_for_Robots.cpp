#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;++i)
    {
        cin>>b[i];
    }
    int x=0,y=0;
    for(int i=0;i<n;++i)
    {
        if(a[i]==1 and b[i]==0)
        {
            x++;
        }
        if(b[i]==1 and a[i]==0)
        {
            y++;
        }
    }
    if(x==0)
    {
        cout<<-1<<"\n";
    }
    else
    {
        // cout<<x<<" "<<y<<"\n";
        // y/x->2/1=2+1=3,2->6=6/2=3+1=4
        cout<<1+y/x<<"\n";
    }
}