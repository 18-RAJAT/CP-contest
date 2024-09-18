#include<bits/stdc++.h>
using namespace std;
#define int long long

int points(int xi,int xj,int vi,int vj)
{
    return((xj-xi)*(vj-vi)<0)?0:abs(xi-xj);
}
void sol()
{
    int n;
    cin>>n;
    vector<int>x(n),v(n);
    for(int i=0;i<n;++i)cin>>x[i];
    for(int i=0;i<n;++i)cin>>v[i];
    int total_distance=0;
    for(int i=0;i<n;++i)
    {
        for(int j=i;j<n;++j)
        {
            total_distance+=points(x[i],x[j],v[i],v[j]);
        }
    }
    cout<<total_distance;
}
signed main()
{
    sol();
    return 0;
}