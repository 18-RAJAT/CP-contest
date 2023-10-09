#include<bits/stdc++.h>
using namespace std;
#define int long long
double getSq(int x1,int y1,int x2,int y2)//calculates the distance between two points
{ 
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
void sol()
{
    double x,y,a1,a2,b1,b2;
    cin>>x>>y>>a1>>a2>>b1>>b2;
    double x1,x2,x3,x4,x5;
    x1=getSq(x,y,a1,a2);
    x2=getSq(x,y,b1,b2);
    x3=getSq(a1,a2,b1,b2);
    x4=getSq(0,0,b1,b2);
    x5=getSq(0,0,a1,a2);
    double M1=min(x1,x2),M2=min(x4,x5);//M3=min(x5,2*pointFind);
    double pointFind=max(M1,M2);
    
    if(x1==M1 && x5==M2)
    {
        double ans=max(x1,x2);
    }
    // else if(x5==M1)
    // {
    //     double ans=max(x1,x2);
    // }
    else if(x2==M1 && x4==M2)
    {
        double ans=max(x4,x5);
    }
    // else if(x4==M2)
    // {
    //     double ans=max(x4,x5);
    // }
    else
    {
        if(x3-pointFind>pointFind)
        {
            pointFind=x3/2;
        }
    }
    cout<<setprecision(11)<<pointFind<<endl;
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