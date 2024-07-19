#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    pair<int,int>pairs[100005];
    vector<int>visited(n,0);
    int ans=0;
    for(int i=n-1;i>=1;--i)
    {
        vector<int>index(i,-1);
        for(int j=0;j<n;++j)
        {
            if(visited[j])continue;
            int temp=a[j]%i;
            if(index[temp]==-1)index[temp]=j;
            else
            {
                pairs[ans++]={index[temp],j},visited[j]=1;
                break;
            }
        }
    }
    cout<<"YES"<<endl;
    for(int i=ans-1;i>=0;--i)
    {
        cout<<pairs[i].second+1<<" "<<pairs[i].first+1<<endl;
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