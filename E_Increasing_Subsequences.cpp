#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int x;
    cin>>x;
    int seq=-1;
    int temp=x;
    while(temp)
    {
        temp>>=1;
        seq++;
    }
    vector<int>ans;
    for(int i=0;i<seq;++i)
    {
        ans.push_back(2*i+1);
    }
    for(int i=seq-1;~i;--i)
    {
        if(((long long)1<<i)&x)
        {
            ans.push_back(2*i);
        }
    }
    cout<<ans.size()<<endl;
    for(auto& it:ans)
    {
        cout<<it<<" ";
    }
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