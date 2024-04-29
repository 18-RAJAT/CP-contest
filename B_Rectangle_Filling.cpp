#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    array<string,30005>fill;
    for(int i=0;i<n;++i)
    {
        cin>>fill[i];
    }
    function<bool(char)>check=[n,m,&fill](char ch)->bool
    {
        int max_x=0,max_y=0,min_x=n-1,min_y=m-1;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(fill[i][j]==ch)
                {
                    min_x=min(min_x,i);
                    min_y=min(min_y,j);
                    max_x=max(max_x,i);
                    max_y=max(max_y,j);
                }
            }
        }
        return (min_x==0 && min_y==0 && max_x==n-1 && max_y==m-1)?true:false;
    };
    cout<<((check('W') || check('B'))?"YES":"NO")<<endl;
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