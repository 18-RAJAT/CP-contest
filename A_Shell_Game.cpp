#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int v[3]={1,2,3};
    int a,b;
    cin>>a>>b;
    swap(v[a-1],v[b-1]);
    int c,d;
    cin>>c>>d;
    swap(v[c-1],v[d-1]);
    int e,f;
    cin>>e>>f;
    swap(v[e-1],v[f-1]);
    cout<<v[n-1];
}
signed main()
{
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    sol();
    return 0;
}