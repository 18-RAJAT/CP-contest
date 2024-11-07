#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m,k;
    cin>>n>>m>>k;
    string s;
    cin>>s;
    int l=min(n,m);
    vector<char>play(l);
    for(int i=0;i<l;++i)
    {
        play[i]=s[i%k];
    }
    int A=0;
    for(auto& it:play)
    {
        if(it=='A')A++;
    }
    int B=l-A;
    int CA=0,CB=0;
    for(int i=0;i<l;++i)
    {
        if(play[i]=='A')CA+=i+1;
        else CB+=i+1;
    }
    for(int i=0;i<l;++i)
    {
        if(play[i]=='A')CA+=i;
        else CB+=i;
    }
    if(n>l)
    {
        CA+=(n-l)*A;
        CB+=(n-l)*B;
    }
    if(m>l)
    {
        CA+=(m-l)*A;
        CB+=(m-l)*B;
    }
    cout<<(CA>CB?"Alice":CB>CA?"Bob":"Draw")<<endl;
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