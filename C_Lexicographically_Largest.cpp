#include<bits/stdc++.h>
using namespace std;
#define int long long
void check_min(int& a,int b)
{
    a=min(a,b);
}
void print(vector<int>&array)
{
    for(auto& it:array)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}
void sol()
{
    int n;
    cin>>n;
    vector<int>array(n);
    for(int i=0;i<n;++i)
    {
        cin>>array[i];
        array[i]+=i+1;
    }
    sort(array.begin(),array.end());
    int nxt=INT_MAX;
    vector<int>dp;
    // sort(array.begin(),array.end());
    reverse(array.begin(),array.end());
    for(auto& it:array)
    {
        check_min(it,nxt);
        dp.push_back(it);
        nxt=it-1;
    }
    print(dp);
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