#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>operation(n);
    iota(operation.begin(),operation.end(),0);
    int sum=0;
    vector<pair<int,int>>matrix;
    for(int i=1;i<=n;++i)
    {
        sum+=((2*i-1)*i);
    }
    for(int i=n-1;i>=0;--i)
    {
        matrix.push_back({1,i});
        matrix.push_back({2,i});
    }
    cout<<sum<<" "<<matrix.size()<<endl;
    for(int i=0;i<matrix.size();++i)
    {
        cout<<matrix[i].first<<" "<<matrix[i].second+1<<" ";
        for(int j=0;j<operation.size();++j)
        {
            cout<<operation[j]+1<<" ";
        }
        cout<<endl;
    }
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