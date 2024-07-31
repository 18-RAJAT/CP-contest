#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    string str;
    int n=s.size();
    int ans=0;
    for(auto it='a';it<='z';++it)
    {
        for(int i=0;i<=n;++i)
        {
            string pass=s.substr(0,i)+it+s.substr(i);
            int total=2;
            for(int j=1;j<pass.size();++j)
            {
                total+=(pass[j]==pass[j-1])?1:2;
            }
            if(ans<total)
            {
                ans=total;
                str=pass;
            }
        }
    }
    cout<<str<<endl;
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