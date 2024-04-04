#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    map<tuple<int,int>,int>open,close;
    for(int i=0;i<n;++i)
    {
        string s;
        cin>>s;
        int c=0,o=0;
        for(int j=0;j<(int)s.size();++j)
        {
            if(s[j]=='(')
            {
                c++;
            }
            else
            {
                (c>0)?c--:o++;
            }
        }
        if(c==0)
        {
            open[{0,o}]++;
            close[{0,o}]++;
        }
        else
        {
            (o==0)?open[{c,0}]++:close[{o,0}]++;
        }
    }
    int ans=0;
    for(int i=0;i<(int)3e5+9;++i)
    {
        ans+=open[{i,0}]*close[{0,i}];
    }
    cout<<ans;
}
signed main()
{
    sol();
    return 0;
}