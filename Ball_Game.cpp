#include<bits/stdc++.h>
using namespace std;
#define int long long
bool check(array<int,2>a,array<int,2>b)
{
    return a[0]*b[1]>b[0]*a[1];
}
void sol()
{
    int n;
    cin>>n;
    vector<array<int,2>>arr;
    for(int i=0;i<n;++i)
    {
        int distance;
        cin>>distance;
        arr.emplace_back(array<int,2>{distance,0});
    }
    vector<int>ans;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        arr[i][1]=x;
    }
    sort(arr.begin(),arr.end(),[&](const array<int,2>&a,const array<int,2>&b){return a[0]<b[0];});
    for(int i=0;i<n;++i)
    {
        // while(!ans.empty() && arr[ans.back()][0]*arr[i][1]<arr[i][0]*arr[ans.back()][1])
        while(!ans.empty() && check(arr[ans.back()],arr[i]))
        {
            ans.pop_back();
        }
        ans.push_back(i);
    }
    cout<<ans.size()<<endl;
}
signed main(){
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
    return 0;
}