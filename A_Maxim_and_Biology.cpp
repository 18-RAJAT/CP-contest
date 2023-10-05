#include<bits/stdc++.h>
using namespace std;
#define int long long
int dist(char a,char b)
{
    int ans=0;
    for(int i=0;i<26;++i)
    {
        if(b==char('A'+(i+a-'A')%26))
        {
            // ans=min(i,26-i);
            ans=i;
            break;
        }
    }
    //for clockwise
    if(ans>13)
    {
        ans=26-ans;
    }
    return ans;
}
int check(char a,char b,char c,char d)
{
    int ans=0;
    ans+=dist(a,'A');//for clockwise
    ans+=dist(b,'C');//for clockwise
    ans+=dist(c,'T');//for anti-clockwise
    ans+=dist(d,'G');//for anti-clockwise
    return ans;
}
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ans=INT_MAX;
    for(int i=0;i<=n-4;++i)
    {
        ans=min(ans,check(s[i],s[i+1],s[i+2],s[i+3]));
    }
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}