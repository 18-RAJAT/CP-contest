#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    vector<int>arr;
    priority_queue<int>pq;
    for(auto& it:a)
    {
        while(!arr.empty() && arr.back()>it)
        {
            int last=arr.back();
            arr.pop_back();
            last++;
            pq.push(-last);
        }
        arr.push_back(it);
    }
    while(pq.size())
    {
        int x=-pq.top();
        while(!arr.empty() && arr.back()>x)
        {
            int last=arr.back();
            arr.pop_back();
            last++;
            pq.push(-last);
        }
        pq.pop();
        arr.push_back(x);
    }
    for(auto& it:arr)cout<<it<<" ";
    cout<<endl;
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