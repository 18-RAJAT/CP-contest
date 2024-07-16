#include<bits/stdc++.h>
using namespace std;
#define int long long
int calc(vector<int>& bit)
{
    int ans=0;
    for(int i=0;i<bit.size();++i)
    {
        if(bit[i]==1)
        {
            ans+=(1LL<<i);
        }
    }
    return ans;
}
void sol()
{
    int n;
    cin>>n;
    vector<int>bit,cur;
    int ans=0,x=0;
    int tmp=n;
    while(n>=1)
    {
        bit.push_back(n%2);
        if(n&1)
        {
            ans++,cur.push_back(x);
        }
        n/=2,x++;
    }
    if(ans==1)
    {
        cout<<ans<<endl;
        cout<<tmp<<endl;
    }
    else
    {
        cout<<ans+1<<endl;
        vector<int>ert;
        ert.push_back(tmp);
        for(int i=0;i<ans;++i)
        {
            bit[cur[i]]=0;//unset
            ert.push_back(calc(bit));
            bit[cur[i]]=1;//set
        }
        reverse(ert.begin(),ert.end());
        for(int i=0;i<ert.size();++i)
        {
            cout<<ert[i]<<" ";
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