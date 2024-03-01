#include<bits/stdc++.h>
using namespace std;
#define int long long
int ask(int x,int find)
{
    cout<<"? "<<x<<" "<<find<<endl;
    int ans;
    cin>>ans;
    return ans;
}
void sol()
{
    int n,m;
    cin>>n>>m;
    int distance1=ask(1,1);
    int distance2=ask(n,1);
    int distance3=ask(n,m);
    int distance4=1e9;
    int find=(2+distance1-(n-distance2+1))/2;
    int x_dist1=n-distance2+find;
    int y_dist1=1+find;
    int y2=(m-distance3-1+distance2)/2;
    int x_dist2=n-distance2+y2;
    int y_dist2=1+y2;
    if(x_dist1>=1 && x_dist1<=n && y_dist1>=1 && y_dist1<=m)
    {
        distance4=ask(x_dist1,y_dist1);
    }
    if(distance4==0)
    {
        cout<<"! "<<x_dist1<<" "<<y_dist1<<endl;
    }
    else
    {
        cout<<"! "<<x_dist2<<" "<<y_dist2<<endl;
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