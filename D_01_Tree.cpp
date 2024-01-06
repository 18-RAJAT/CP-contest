#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    if(a[0]==1)
    {
        cout<<"NO"<<endl;
        return;
    }
    bool visited=false;
    queue<int>q;
    q.push(0);
    int i=0;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        if(x>=n)
        {
            break;
        }
        if(x==n-1)
        {
            visited=true;
            break;
        }
        q.push(2*x+1);
        q.push(2*x+2);
        i++;
    }
    if(visited)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
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