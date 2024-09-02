#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int check=(sqrtl(n));
    if(check*check!=n)
    {
        cout<<"No"<<endl;
        return;
    }
    int ans=0;
    array<array<char,450>,450>mat;
    for(int i=0;i<check;++i)
    {
        for(int j=0;j<check;++j)
        {
            mat[i][j]=s[ans++];
        }

    }
    int ok=1;
    for(int i=0;i<check;++i)
    {
        if(mat[0][i]!='1' || mat[check-1][i]!='1')
        {
            ok=0;break;
        }
    }
    for(int i=0;i<check;++i)
    {
        if(mat[i][0]!='1' || mat[i][check-1]!='1')
        {
            ok=0;break;
        }
    }
    for(int i=1;i<check-1;++i)
    {
        if(!ok)break;
        for(int j=1;j<check-1;++j)
        {
            if(mat[i][j]!='0')
            {
                ok=0;break;
            }
        }
    }
    cout<<(ok?"Yes\n":"No\n");
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