#include<bits/stdc++.h>
using namespace std;
#define int long long

//Rajat joshi template
vector<int>getdivs(int x)
{
    vector<int>divs;
    if(x==0)return divs;
    int diff=abs(x);
    for(int d=1;d*d<=diff;++d)
    {
        if(diff%d==0)
        {
            divs.emplace_back(d);
            divs.emplace_back(-d);
            if(d!=diff/d)
            {
                divs.emplace_back(diff/d);
                divs.emplace_back(-(diff/d));
            }
        }
    }
    return divs;
}
void sol()
{
    int n,m,q;
    cin>>n>>m>>q;
    vector<int>a(n),b(m);
    for(auto& x:a)cin>>x;
    for(auto& x:b)cin>>x;
    int A=accumulate(a.begin(),a.end(),0LL),B=accumulate(b.begin(),b.end(),0LL);
    vector<int>C(n),D(m);
    for(int i=0;i<n;++i)C[i]=A-a[i];
    for(int i=0;i<m;++i)D[i]=B-b[i];
    sort(C.begin(),C.end());
    sort(D.begin(),D.end());
    while(q--)
    {
        int x;
        cin>>x;
        bool ok=0;
        vector<int>divs=getdivs(x);
        for(auto& d:divs)
        {
            int c=x/d;
            if(binary_search(C.begin(),C.end(),d) && binary_search(D.begin(),D.end(),c))
            {
                ok=1;
                break;
            }
        }
        cout<<(ok?"YES":"NO")<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}