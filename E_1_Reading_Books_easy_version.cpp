#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>both,alice,bob;
    for(int i=0;i<n;++i)
    {
        int t,a,b;
        cin>>t>>a>>b;
        if(a && b)both.push_back(t);
        else if(a)alice.push_back(t);
        else if(b)bob.push_back(t);
    }
    int ans=min(alice.size(),bob.size());
    if(both.size()+ans<k)
    {
        cout<<-1;
        return;
    }
    sort(alice.begin(),alice.end());
    sort(bob.begin(),bob.end());
    for(int i=0;i<ans;++i)
    {
        both.push_back(alice[i]+bob[i]);
    }
    sort(both.begin(),both.end());
    both.resize(k);
    int read=0;
    for(auto& it:both)read+=it;
    cout<<read;
}
signed main()
{
    sol();
    return 0;
}