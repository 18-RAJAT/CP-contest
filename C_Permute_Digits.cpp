#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string a;
    int b;
    cin>>a>>b;
    int ans=-1;    
    function<int(string)>convert=[&](string x)->int
    {
        int y=0;
        for(int i=0;i<x.size();++i)
        {
            y=y*10+(x[i]-'0');
        }
        return y;
    };
    function<void(string)>find=[&](string s)->void
    {
        if(s[0]=='0')
        {
            ans=ans;
        }
        else
        {
            int x=convert(s);
            if(x<=b)
            {
                ans=max(ans,x);
            }
        }
    };
    // function<void(string,string)>permute=[&](string s,string t)->void
    // {
    //     if(s.size()==0)
    //     {
    //         find(t);
    //     }
    //     else
    //     {
    //         for(int i=0;i<s.size();++i)
    //         {
    //             string x=s.substr(0,i)+s.substr(i+1);
    //             permute(x,t+s[i]);
    //         }
    //     }
    // };
    // permute(a,"");
    // cout<<ans<<endl;
    sort(a.begin(),a.end());
    do
    {
        find(a);
    }
    while(next_permutation(a.begin(),a.end()));
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}