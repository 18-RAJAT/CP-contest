#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
string s,t,ans;
char str[]={'a','b','c'};
int test1()
{
    ans="";
    for(int i=0;i<n;++i)
    {
        ans+=str[0];
    }
    for(int i=0;i<n;++i)
    {
        ans+=str[1];
    }
    for(int i=0;i<n;++i)
    {
        ans+=str[2];
    }
    for(int i=0;i<n*3;++i)
    {
        if(ans.substr(i,2)==s || ans.substr(i,2)==t)return false;
    }
    return true;
}
int test2()
{
    ans="";
    for(int i=0;i<n;++i)
    {
        ans+=str[0],ans+=str[1];
    }
    for(int i=0;i<n;++i)
    {
        ans+=str[2];
    }
    for(int i=0;i<n*3;++i)
    {
        if(ans.substr(i,2)==s || ans.substr(i,2)==t)return false;
    }
    return true;
}
void sol()
{
    cin>>n;
    cin>>s>>t;
    do
    {
        if(test1() || test2())
        {
            cout<<"YES"<<endl;
            cout<<ans;
            return;
        }
    }while(next_permutation(str,str+3));
    cout<<"NO";
}
signed main()
{
    sol();
    return 0;
}