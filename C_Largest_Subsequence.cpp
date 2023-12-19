#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    stack<pair<char,int>>stk;
    for(int i=0;i<n;++i)
    {
        auto ch=s[i];
        while(!stk.empty() && ch>stk.top().first)
        {
            stk.pop();
        }
        stk.push({ch,i});
    }
    vector<int>ans;
    string str="";
    while(!stk.empty())
    {
        ans.push_back(stk.top().second);
        str+=stk.top().first;
        stk.pop();
    }
    int res=ans.size();
    reverse(str.begin(),str.end());
    for(int i=0;i<ans.size();++i)
    {
        s[ans[i]]=str[i];
        if(str[i]==str[0])
        {
            res--;
        }
    }
    cout<<(is_sorted(s.begin(),s.end())?res:-1)<<endl;
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