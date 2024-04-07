#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ok=0;
    map<int,int>m;
    for(int i=0;i<n;++i)
    {
        if(s[i]=='1')
        {
            ok++,m[i]++;
        }
    }
    if(ok==2)
    {
        bool f=true ;
        for(auto i=m.begin();i!=m.end();++i)
        {
            if((m.begin()->first==i->first+1 || (m.begin()->first==i->first-1)))
            {
                f=false;
            }
        }
        if(f==false)
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    if(ok%2==0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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