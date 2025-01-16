#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,arr[1000005];
string s;
map<int,int>mp;
vector<pair<int,int>>ans;
void Kmp(int i)
{
    arr[i]=0;
    for(int j=i+1;j<s.size();++j)
    {
        int k=arr[j-1];
        while(k>=1 && s[k]!=s[j])k=arr[k-1];
        if(s[k]==s[j])k++;
        arr[j]=k,mp[k]++;
    }
}
void sol()
{
    cin>>s;
    ans.clear();
    Kmp(0);
    int res=arr[s.size()-1];
    ans.push_back({s.size(),1});
    for(int i=s.size()-1;~i;--i)mp[arr[i-1]]+=mp[i];
    while(res>=1)
    {
        ans.push_back({res,mp[res]+1});
        res=arr[res-1];
    }
    cout<<ans.size()<<endl;
    for(int i=ans.size()-1;~i;--i)
    {
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
}
signed main()
{
    sol(); 
    return 0;
}