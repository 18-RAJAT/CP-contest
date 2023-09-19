#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(auto& it:a)
    {
        cin>>it;
    }
    vector<int>res(k,0);
    auto temp=a;
    int start=0,end=n-1;
    
    sort(temp.begin(),temp.end());
    for(auto& it:temp)
    {
        while(a[start]<it && start<n)
        {
            start++;
        }
        while(a[end]<it && end>=0)
        {
            end--;
        }
        int find=2*(end-start+1);
        res[it-1]=find;
    }
    for(auto& it:res)
    {
        cout<<it<<" ";
    }
    cout<<"\n";
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