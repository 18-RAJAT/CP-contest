#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    char ch[n+1];
    cin>>ch;
    int frq[27];
    memset(frq,0,sizeof(frq));
    auto convert=[](char ch)->int
    {
        return ch-'A'+1;
    };
    for(int i=0;i<n;++i)
    {
        frq[convert(ch[i])]++;
    }
    int cnt=0;
    for(int i=1;i<=26;++i)
    {
        if(frq[i]>=i)
        {
            cnt++;
        }
    }
    cout<<cnt<<endl;
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