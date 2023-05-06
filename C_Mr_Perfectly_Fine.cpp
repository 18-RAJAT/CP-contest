#include<bits/stdc++.h>
using namespace std;

void sol()
{
    int n;
    cin>>n;
    int ans=INT_MAX;
    set<int>s1,s2;
    for(int i=0;i<n;++i)
    {
        int m;
        cin>>m;
        string s;
        cin>>s;

        if(s[0]=='1')
        {
            s1.insert(m);
        }
        if(s[1]=='1')
        {
            s2.insert(m);
        }
        if(s[0]=='1' and s[1]=='1')
        {
            ans=min<int>(ans,m);
        }
    }
    if(s1.empty() or s2.empty())
    {
        cout<<"-1"<<"\n";
        return;
    }
    ans=min<int>(ans,(*s1.begin())+(*s2.begin()));
    cout<<ans<<"\n";
}
int main()
{
    int testCases;
    cin>>testCases;
    while(testCases--)
    {
        sol();
    }
    return 0;
}