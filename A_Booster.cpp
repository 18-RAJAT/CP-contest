#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int blocked=0,cur=0;
    for(int i=0;i<n;++i)
    {
        if(s[i]=='#')cur++;
        else blocked=max(blocked,cur),cur=0;
    }
    blocked=max(blocked,cur);
    cout<<blocked<<endl;
}
signed main()
{
    sol();
    return 0;
}