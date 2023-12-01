#include<bits/stdc++.h>
using namespace std;
#define int long long
int dist(int x1,int y1,int x2,int y2)
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
void sol()
{
    int n;
    cin>>n;
    int sx,sy;
    cin>>sx>>sy;
    int x,y;
    int sum=0;
    int mx=0;
    int idx=0;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        int d=dist(sx,sy,x,y);
        if(d>mx)
        {
            mx=d;
            idx=i+1;
        }
        sum+=d;
    }
    if(sum%2==0)
    {
        cout<<"Second"<<endl;
        fflush(stdout);
        cin>>x;
    }
    else
    {
        cout<<"First"<<endl;
        fflush(stdout);
        cin>>x;
        sum-=mx;
    }
    for(int i=1;i<n;i++)
    {
        cout<<idx<<endl;
        fflush(stdout);
        cin>>x>>y;
        sum-=mx;
        mx=0;
        for(int j=0;j<n;j++)
        {
            if(j+1==idx)
            {
                continue;
            }
            int d=dist(x,y,sx,sy);
            if(d>mx)
            {
                mx=d;
                idx=j+1;
            }
        }
        if(sum%2==0)
        {
            cout<<"Second"<<endl;
            fflush(stdout);
            cin>>x;
        }
        else
        {
            cout<<"First"<<endl;
            fflush(stdout);
            cin>>x;
            sum-=mx;
        }
    }
    return;
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