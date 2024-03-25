#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    int ans=1e9;
    for(int i=1;i<(1<<s.size());++i)
    {
        string str;
        for(int j=0;j<s.size();++j)
        {
            if((i>>j)&1)
            {
                str+=s[j];
            }
        }
        if(sqrt(stoi(str))==(int)sqrt(stoi(str)) && stoi(str)!=0 && str[0]!='0' && str.size()<=s.size())
        {
            ans=min(ans,(int)s.size()-__builtin_popcount(i));
        }
    }
    cout<<(ans==1e9?-1:ans);
}
signed main()
{
    sol();
    return 0;
}