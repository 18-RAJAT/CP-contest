#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    vector<string>s(8);
    for(int i=0;i<8;++i)
    {
        cin>>s[i];
    }
    set<int>r,c;
    for(int i=0;i<8;++i)
    {
        for(int j=0;j<8;++j)
        {
            if(s[i][j]=='#')
            {
                r.insert(i);
                c.insert(j);
            }
        }
    }
    int ans=0;
    for(int i=0;i<8;++i)
    {
        for(int j=0;j<8;++j)
        {
            if(s[i][j]=='.'&&r.count(i)==0&&c.count(j)==0)ans++;
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}