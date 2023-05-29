#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    vector<int>u,v;
    for(int i=0;i<n;++i)
    {
        int x;cin>>x;
        if(x&1)
        {
            u.push_back(x);
        }
        else
        {
            v.push_back(x);
        }
    }
    if(v.size()<u.size())
    {
        swap(u,v);
    }
    sort(v.begin(),v.end());
    int M=max<int>(v.size()-u.size()-1,0);
    int ans=0;

    for(int i=0;i<M;++i)
    {
        ans+=v[i];
    }
    cout<<ans<<"\n";
}