#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
// int x[N],y[N];
// int distance(int a,int b)
// {
//     return abs(x[a]-x[b])+abs(y[a]-y[b]);
// }

void sol()
{
    int n,k,a,b;
    cin>>n>>k>>a>>b;
    vector<pair<int,int>>v(n);
    for(int i=0;i<n;++i)
    {
        cin>>v[i].first>>v[i].second;
    }
    int x1=v[a-1].first;
    int y1=v[a-1].second;
    int x2=v[b-1].first;
    int y2=v[b-1].second;
    int id1,id2;
    int dst1=INT64_MAX/2,dst2=INT64_MAX/2;
    for(int i=0;i<k;++i)
    {
        if(abs(x1-v[i].first)+abs(y1-v[i].second)<dst1)
        {
            dst1=abs(x1-v[i].first)+abs(y1-v[i].second);
            id1=i;
        }
        if(abs(x2-v[i].first)+abs(y2-v[i].second)<dst2)
        {
            dst2=abs(x2-v[i].first)+abs(y2-v[i].second);
            id2=i;
        }
    }
    int v1=dst1+dst2;
    int v2=abs(x1-x2)+abs(y1-y2);
    cout<<min(v1,v2)<<endl;
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