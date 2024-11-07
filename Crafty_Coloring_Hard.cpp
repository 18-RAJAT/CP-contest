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
    int ok=l/k,rem=l%k;
    int A=0,B=0;
    for(auto& it:s)
    {
        (it=='A')?A++:B++;
    }
    int AA=ok*A,BB=ok*B;
    for(int i=0;i<rem;++i)
    {
        (s[i]=='A')?AA++:BB++;
    }
    int row_a=min(AA,n),row_b=min(BB,n-row_a);
    int col_a=min(AA,m),col_b=min(BB,m-col_a);
    if(n>l)
    {
        int ex=n-l,cy=ex/k,rem=ex%k;
        int exA=cy*A,exB=cy*B;
        for(int i=0;i<rem;++i)
        {
            (s[i]=='A')?exA++:exB++;
        }
        row_a+=min(exA,n-row_a-row_b);
        row_b+=min(exB,n-row_a-row_b);
    }
    if(m>l)
    {
        int ex=m-l,cy=ex/k,rem=ex%k;
        int exA=cy*A,exB=cy*B;
        for(int i=0;i<rem;++i)
        {
            (s[i]=='A')?exA++:exB++;
        }
        col_a+=min(exA,m-col_a-col_b);
        col_b+=min(exB,m-col_a-col_b);
    }
    int alice=row_a*col_a,bob=(n*m-alice);
    if(alice>bob)cout<<"Alice"<<endl;
    else if(bob>alice)cout<<"Bob"<<endl;
    else cout<<"Draw"<<endl;
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