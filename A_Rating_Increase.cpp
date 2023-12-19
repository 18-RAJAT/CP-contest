#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    int n=s.size();
    string start="",end="";
    bool ok=false;
    for(int i=0;i<n;++i)
    {
        if(i==0)
        {
            start+=s[i];
        }
        else
        {
            if(s[i]!='0')
            {
                ok=true;
            }
            if(ok==false)
            {
                start+=s[i];
            }
            else
            {
                end+=s[i];
            }
        }
    }
    if(end=="")
    {
        cout<<-1<<endl;
        return;
    }
    function<int(string)> stoi=[](string s)->int
    {
        int ans=0;
        for(auto &ch:s)
        {
            ans=ans*10+(ch-'0');
        }
        return ans;
    };
    int st1=stoi(start);
    int st2=stoi(end);
    if(st1==st2)
    {
        cout<<"-1"<<endl;
    }
    else if(st2<st1)
    {
        cout<<"-1"<<endl;
    }
    else
    {
        cout<<st1<<" "<<st2<<endl;
    }
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