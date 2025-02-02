#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n),b(n),c(n);
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<n;++i)cin>>b[i];
    for(int i=0;i<n;++i)cin>>c[i];
    sort(a.rbegin(),a.rend());
    sort(b.rbegin(),b.rend());
    sort(c.rbegin(),c.rend());
    
    //1*2+2*3+3*1
    //clc->>i*n+j*n+l
    auto f=[&](int i,int j,int l){return a[i]*b[j]+b[j]*c[l]+c[l]*a[i];};
    auto calc=[&](int i,int j,int l){return ((i*n+j)*n+l);};

    priority_queue<pair<int,array<int,3>>>pq;
    unordered_set<int>st;
    pq.push({f(0,0,0),{0,0,0}});
    st.insert(calc(0,0,0));
    int ans=0;
    while(k--)
    {
        int F=pq.top().first;
        array<int,3>u=pq.top().second;
        pq.pop();
        ans=F;
        int i=u[0],j=u[1],l=u[2];
        if(i+1<n)
        {
            int x=calc(i+1,j,l);
            if(!st.count(x))
            {
                st.insert(x);
                pq.push({f(i+1,j,l),{i+1,j,l}});
            }
        }
        if(j+1<n)
        {
            int x=calc(i,j+1,l);
            if(!st.count(x))
            {
                st.insert(x);
                pq.push({f(i,j+1,l),{i,j+1,l}});
            }
        }
        if(l+1<n)
        {
            int x=calc(i,j,l+1);
            if(!st.count(x))
            {
                st.insert(x);
                pq.push({f(i,j,l+1),{i,j,l+1}});
            }
        }
    }
    cout<<ans;
}
signed main()
{
    sol();
    return 0;
}