#include<bits/stdc++.h>
using namespace std;
#define int long long
string s1,s2;
int ans,x,y,z,res;
void recur(int id,int cnt)
{
    if(id==z)
    {
        res++;
        if(cnt+x==y)ans++;
        return;
    }
    recur(id+1,cnt+1);
    recur(id+1,cnt-1);
}
void sol()
{
    cin>>s1>>s2;
    for(int i=0;i<s1.size();++i)
    {
        (s1[i]=='+')?x++:x--;
    }
    for(int i=0;i<s2.size();++i)
    {
        if(s2[i]=='+')y++;
        else if(s2[i]=='-')y--;
        else z++;
    }
    recur(0,0);
    cout<<setprecision(12)<<fixed<<ans/double(res);
}
signed main()
{
    sol();
    return 0;
}