#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string S;
    cin>>S;
    int n=S.length();
    set<string>st;
    vector<string>ans;
    int pos=0;
    string str="";
    while(pos<n)
    {
        bool ok=false;
        string cur="";
        for(int i=1;pos+i<=n;++i)
        {
            string s=S.substr(pos,i);
            if(s>=str && st.find(s)==st.end())
            {
                cur=s;
                st.insert(s);
                str=s;
                pos+=i;
                ans.push_back(s);
                ok=true;
                break;
            }
        }
        if(!ok) break;
    }
    cout<<ans.size()<<endl;
    for(auto& it:ans)
    {
        cout<<it<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}