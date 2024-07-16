#include<bits/stdc++.h>
using namespace std;
#define int long long
struct points
{
    int wt,id,pos;
};
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<points>pt(m);
    for(int i=0;i<m;++i)
    {
        cin>>pt[i].pos>>pt[i].wt;
        pt[i].id=i+1;
    }
    sort(pt.begin(),pt.end(),[&](points a,points b)->bool
    {
        return a.wt<b.wt?true:false;
    });
    int sum=0;
    for(int i=0;i<m;++i)
    {
        if(2*n>i)sum+=pt[i].wt;
        else
        {
            pt.pop_back();
        }
    }
    sort(pt.begin(),pt.end(),[&](points a,points b)->bool
    {
        return a.pos<b.pos?true:false;
    });
    cout<<sum<<endl;
    for(int i=0;i<n;++i)
    {
        cout<<pt[i].id<<" "<<pt[2*n-i-1].id<<endl;
    }
    cout<<endl;
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