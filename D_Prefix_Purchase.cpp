#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    map<int,int> mp;
    set<int> st;
    for(int i=1;i<=n;++i)
    {
        int x;
        cin>>x;
        mp[x]=i;
        st.insert(x);
    }
    int k;
    cin>>k;
    int a[n+1];
    memset(a,0,sizeof(a));
    int last=0,last1=0,calc=INT_MAX;
    for(auto& it:st)
    {
        int j=mp[it];
        if(j<=last)
        {
            continue;
        }
        // else
        // {
        //     j--;
        // }
        // if(j!=0)
        // {
        //     break;
        // }
        int diff=it-last1;
        int y=k/diff;
        y=min(y,calc);
        // cout<<y<<" "<<diff<<" "<<it<<"\n";
        for(int i=last+1;i<=j;++i)
        {
            a[i]=y;
        }
        last=j;
        last1=it;
        // cout<<last<<" "<<last1<<"\n";
        calc=y;
        k-=(y*diff);
    }
    for(int i=1;i<=n;++i)
    {
        cout<<a[i]<<" ";
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