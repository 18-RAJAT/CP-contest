#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1005;
struct Point
{
    int x,y;
};

void sol()
{
    int n;
    cin>>n;
    vector<Point>a(n);
    vector<int>P(n),Q(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i].x>>a[i].y;
        P[i]=a[i].x;
        Q[i]=a[i].y;
    }
    sort(P.begin(),P.end());
    sort(Q.begin(),Q.end());
    vector<int>T1,T2;
    for(int i=0;i<=N;++i)
    {
        int res=i*n/N;
        if(res>=n)res=n-1;
        T1.push_back(P[res]);
        T2.push_back(Q[res]);
    }
    sort(T1.begin(),T1.end());
    T1.erase(unique(T1.begin(),T1.end()),T1.end());
    sort(T2.begin(),T2.end());
    T2.erase(unique(T2.begin(),T2.end()),T2.end());
    int x=-1,y=0,z=0;
    vector<Point>NewPt=a;
    sort(NewPt.begin(),NewPt.end(),[](Point a,Point b){return a.x<b.x;});
    for(auto& it:T1)
    {
        vector<int>L,R;
        for(auto& arr:a)
        {
            if(arr.x<it)L.push_back(arr.y);
            else R.push_back(arr.y);
        }
        sort(L.begin(),L.end());
        sort(R.begin(),R.end());
        int S1=L.size(),S2=R.size();
        for(auto& it1:T2)
        {
            int p=R.end()-lower_bound(R.begin(),R.end(),it1),q=S2-p;
            int r=L.end()-lower_bound(L.begin(),L.end(),it1),s=S1-r;
            int mn=min({p,r,q,s});
            if(mn>x)
            {
                x=mn,y=it,z=it1;
            }
        }
    }
    cout<<x<<"\n"<<y<<" "<<z<<"\n";
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