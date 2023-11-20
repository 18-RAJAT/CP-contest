#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int cnt=0;
    for(int i=0;i<n;++i)
    {
        if(s[i]=='B') cnt++;
    }
    int add=k-cnt;
    if(add==0)
    {
        cout<<0;
        return;
    }
    cout<<1<<endl;
    int cntA=0,cntB=0;
    for(int i=0;i<n;++i)
    {
        if(s[i]=='A')
        {
            cntA++;
        }
        else
        {
            cntB++;
        }
        if(cntA==add)
        {
            cout<<i+1<<" "<<'B';
            return;
        }
        if(cntB==-add)
        {
            cout<<i+1<<" "<<'A';
            return;
        }
    }
} 

signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        sol();
        cout<<endl;
    }
    return 0;
}