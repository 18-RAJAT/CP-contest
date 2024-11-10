#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Fishing
{
    int x,y;
    bool ok;
};
void sol()
{
    int n;
    cin>>n;
    vector<Fishing>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i].x>>a[i].y;
        a[i].ok=(i<n);
    }
    int m=4;
    vector<pair<int,int>>polygon={{0,0},{100000,0},{100000,100000},{0,100000}};
    cout<<m<<endl;
    for(int i=0;i<m;++i)
    {
        cout<<polygon[i].first<<" "<<polygon[i].second<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}