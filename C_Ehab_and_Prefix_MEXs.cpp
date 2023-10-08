#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector<int>visited(n+1);
    set<int>st;
    for(int i=0;i<n;i++)
    for(auto& it:visited)
    {
        visited[a[i]]=1;
    }
    for(int i=0;i<=n;i++)
    {
        if(!visited[i])
        {
            st.insert(i);
        }
    }
    vector<int>b;
    int preCompute=-1;
    for(int i=0;i<n;i++)
    {
        if(st.empty())
        {
            b.push_back(preCompute);
        }
        else
        {
            b.push_back(*st.begin());
            st.erase(st.begin());
        }
        preCompute=b.back();
        if(i<n and a[i]!=a[i+1])
        {
            st.insert(a[i]);
        }
    }
    for(auto& it:b)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}
signed main()
{
    sol();
    return 0;
}