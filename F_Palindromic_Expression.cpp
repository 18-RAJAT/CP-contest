#include<bits/stdc++.h>
using namespace std;
#define int long long
int pali(int x)
{
    if(x==0)return 0;
    while(x)
    {
        if(x%10==0)return 0;
        x/=10;
    }
    return 1;
}
int exp(int x)
{
    int ret=0;
    while(x)
    {
        ret=ret*10+x%10;
        x/=10;
    }
    return ret;
}
string dfs(int x)
{
    if(pali(x) && x==exp(x))return to_string(x);
    for(int i=2;i*i<=x;++i)
    {
        if(x%i==0 && pali(i))
        {
            int j=exp(i);
            string ret=dfs(x/(i*j));
            if(x/i%j==0 && ret.size())
            {
                return to_string(i)+"*"+ret+"*"+to_string(j);
            }
        }
    }
    return "";
}
void sol()
{
    int n;
    cin>>n;
    string ret=dfs(n);
    if(ret.size())cout<<ret;
    else cout<<-1;
}
signed main()
{
    sol();
    return 0;
}