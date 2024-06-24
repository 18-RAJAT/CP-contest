#include<bits/stdc++.h>
using namespace std;
#define int long long
int recur(vector<int>a,int start)
{
    int ans=0,count0=0,count1=0;
    for(int i=start;i<a.size();++i)
    {
        if(a[i]==0)count0++;
        if(a[i]==1)count1++;
    }
    if(count0>0)return 0;
    if(count1==a.size())return 1;
    for(int i=start;i<a.size();++i)
    {
        if(a[i]>1)ans+=a[i];
    }
    return ans;
}
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ans=INT_MAX;
    for(int i=0;i+1<n;++i)
    {
        vector<int>pos;
        for(int j=0;j<n;++j)
        {
            if(i==j)
            {
                pos.push_back(stoi(s.substr(j,2))),j++;
            }
            else
            {
                pos.push_back(s[j]-'0');
            }
        }
        ans=min(ans,recur(pos,0));
    }
    cout<<ans<<endl;
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