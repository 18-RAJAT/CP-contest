#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(vector<int>& array,int n,int m,map<int,int>& a)
{
    int ans=0;
    sort(array.begin(),array.end());
    for(int i=0;i<n;++i)
    {
        if(m<array[i])break;
        int temp=m;
        int control=0,calculate_flow=array[i]*(a[array[i]]);
        if(calculate_flow<temp)
        {
            control+=calculate_flow;
            temp-=calculate_flow;
            int next_step=array[i]+1;
            if(a[next_step])
            {
                int j=temp/next_step;
                j=min(a[next_step],j);
                temp-=(next_step*j),control+=(next_step*j);
                control+=min({temp,a[array[i]],a[next_step]-j});
            }
        }
        else
        {
            int j=temp/array[i];
            j=min(a[array[i]],j);
            int p=array[i]*j;
            temp-=(p),control+=(p);
            control+=(min({j,temp,a[array[i]+1]}));
        }
        ans=max(ans,control);
    }
    cout<<ans<<endl;
}
void sol()
{
    int n,m;
    cin>>n>>m;
    map<int,int>a;
    vector<int>array(n);
    for(int i=0;i<n;++i)
    {
        cin>>array[i];
    }
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        a[array[i]]=x;
    }
    solve(array,n,m,a);
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