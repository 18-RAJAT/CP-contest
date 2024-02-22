#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int x1,y1,x2,y2,x3,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    int point_of_right_up=(x2-x1)*(y3-y1);
    int point_of_left_down=(x3-x1)*(y2-y1);
    if(point_of_right_up-point_of_left_down<0)
    {
        cout<<"RIGHT"<<endl;
    }
    else if(point_of_right_up-point_of_left_down>0)
    {
        cout<<"LEFT"<<endl;
    }
    else
    {
        cout<<"TOUCH"<<endl;
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