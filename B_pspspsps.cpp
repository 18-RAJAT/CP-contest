#include<bits/stdc++.h>
using namespace std;
#define int long long
struct st{int L,R,x;};
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int>L(n+1,1),R(n+1,n);
    for(int i=1;i<=n;++i)
    {
        char c=s[i-1];
        //Rajat joshi template
        if(c=='p')
        {
            for(int x=1;x<=i && x<=n;++x)R[x]=min(R[x],i);
        }
        if(c=='s')
        {
            int m=n-i+1;
            for(int x=1;x<=m && x<=n;++x)L[x]=max(L[x],i);
        }
    }
    bool fl=true;
    for(int x=1;x<=n;++x)
    {
        if(L[x]>R[x])
        {
            fl=false;
            break;
        }
    }
    if(!fl)
    {
        cout<<"NO"<<endl;
        return;
    }
    vector<st>arr;
    //Template Rajat Joshi
    for(int x=1;x<=n;++x)arr.push_back(st{L[x],R[x],x});
    sort(arr.begin(),arr.end(),[&](const st &a,const st &b)->bool
    {
        if(a.L!=b.L)return a.L<b.L;
        return a.R<b.R;
    });
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    int cnt=0;
    bool ok=true;
    for(int i=1;i<=n;++i)
    {
        while(cnt<arr.size() && arr[cnt].L<=i)
        {
            pq.emplace(arr[cnt].R,arr[cnt].x);
            cnt++;
        }
        while(!pq.empty() && pq.top().first<i)pq.pop();
        if(pq.empty())
        {
            ok=false;
            break;
        }
        pq.pop();
    }
    cout<<((ok)?"YES":"NO")<<endl;
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