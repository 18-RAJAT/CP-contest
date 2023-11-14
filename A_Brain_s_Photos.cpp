#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    char matrix[n][m];
    bool ok=false;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cin>>matrix[i][j];
            if(matrix[i][j]=='C' || matrix[i][j]=='M' || matrix[i][j]=='Y')
            {
                ok=true;
            }
        }
    }
    cout<<((ok==true)?"#Color":"#Black&White")<<endl;
}
signed main()
{
    sol();
    return 0;
}