#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k,m;
    cin>>n>>k>>m;
    string s;
    cin>>s;
    s="L"+s+"L";//boundary handling
    int current=0;
    while(current<=n)
    {
        if(s[current]=='L')
        {
            int update=-1,res=-1;
            for(int i=1;i<=k;++i)
            {
                if(current+i<=n+1)
                {
                    (s[current+i]=='W'?res=current+i:(s[current+i]=='L'?update=current+i:0));
                }
            }
            if(~update)current=update;
            else if(~res)current=res;
            else break;
        }
        else if(s[current]=='W')
        {
            m--;
            if(m<0)break;
            if(s[current+1]=='L' || s[current+1]=='W')current++;
            else break;
        }
    }
    cout<<((current==n+1)?"YES":"NO")<<endl;
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