#include<bits/stdc++.h>
using namespace std;
#define int long long
int recur(string s,string t)
{
    int ok=0,i=0;
    for(;i<s.size();)
    {
        if(s.substr(i,t.size())==t)
        {
            i+=t.size(),ok=1;
        }
        else if(s[i]=='a')i++;
        else return 0;
    }
    return ok;
}
void sol()
{
    string s;
    cin>>s;
    unordered_set<string>st;
    for(int i=0;i<s.size();++i)
    {
        for(int j=1;j<=s.size()-i;++j)
        {
            string t=s.substr(i,j);
            if(!st.count(t) && t!="a")
            {
                if(recur(s,t))st.insert(t);
            }
        }
    }
    cout<<st.size()<<endl;
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