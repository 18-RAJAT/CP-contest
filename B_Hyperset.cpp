#include<bits/stdc++.h>
using namespace std;
#define int long long
string recur(string s1,string s2)
{
    string ans(s1.size(),' ');
    for(int i=0;i<s1.size();++i)
    {
        (s1[i]==s2[i])?ans[i]=s1[i]:ans[i]=(s1[i]^s2[i]^'S'^'E'^'T');
    }
    return ans;
}
void sol()
{
    int n,k;
    cin>>n>>k;
    string s;
    map<string,int>mp;
    vector<string>vs;
    for(int i=0;i<n;++i)
    {
        cin>>s;
        mp[s]++;
        vs.push_back(s);
    }
    int ans=0;
    for(int i=0;i<n;++i)
    {
        mp[vs[i]]--;
        for(int j=i+1;j<n;++j)
        {
            s=recur(vs[i],vs[j]);
            int temp=(mp.find(s)==mp.end())?0:mp[s];
            ans+=temp;
        }
    }
    cout<<ans/2<<endl;
}
signed main()
{
    sol();
    return 0;
}