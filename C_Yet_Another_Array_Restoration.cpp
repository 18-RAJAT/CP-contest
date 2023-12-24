#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,x,y;
    cin>>n>>x>>y;
    int difference=y-x;
    for(int i=n-1;~i;--i)
    {
        if(difference%i==0)
        {
            int l=y;
            int diff=difference/i;
            for(int j=0;j<n;++j)
            {
                cout<<l<<" ";
                if(l<=y)
                {
                    l-=diff;
                    if(l<1)
                    {
                        l=y+diff;
                    }
                }
                else
                {
                    l+=diff;
                }
            }
            cout<<"\n";
            break;
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
  }
  return 0;
}