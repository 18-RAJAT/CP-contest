#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n),b(n),ar(n),br(n);
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<n;++i)cin>>b[i];
    for(int i=1;i<n;++i)ar.push_back(a[i]-a[i-1]);
    for(int i=1;i<n;++i)br.push_back(b[i]-b[i-1]);
    sort(ar.begin(),ar.end());
    sort(br.begin(),br.end());
    cout<<((a[0]==b[0] && ar==br)?"Yes":"No");
}
signed main()
{
    sol();
    return 0;
}