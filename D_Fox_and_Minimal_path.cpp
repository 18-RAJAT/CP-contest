#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1005][1005];
void sol()
{
    int n;
    cin>>n;
    int x=1,ans=3;
    while(n)
    {
        int bits=0;
        for(;((1<<bits)<n);)bits++;
        if(n%2==0)
        {
            int u=ans++,v=ans++;
            a[x][u]=a[u][x]=1;
            a[x][v]=a[v][x]=1;
            x=ans++;
            a[u][x]=a[x][u]=1;
            a[v][x]=a[x][v]=1;
            n/=2;
        }
        else
        {
            int y=x;
            for(int i=1;i<2*bits-1;++i)
            {
                int check=ans++;
                a[y][check]=a[check][y]=1;
                y=check;
            }
            a[y][2]=a[2][y]=1,n--;
        }
    }
    ans--;
    cout<<ans<<endl;;
    for(int i=1;i<=ans;++i)
    {
        for(int j=1;j<=ans;++j)
        {
            cout<<(a[i][j]?'Y':'N');
        }
        cout<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}