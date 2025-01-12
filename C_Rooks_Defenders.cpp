#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,q;
    cin>>n>>q;
    unordered_map<int,int>ar,br;
    while(q--)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int x,y;
            cin>>x>>y;
            ar[x]++,br[y]++;
        }
        else if(t==2)
        {
            int x,y;
            cin>>x>>y;
            ar[x]--,br[y]--;
        }
        else
        {
            int x1,x2,y1,y2;
            cin>>x1>>y1>>x2>>y2;
            int f=1,ok=1;
            if(ar.size()!=n && br.size()!=n)
            {
                for(int i=x1;i<=x2;++i)
                {
                    if(ar[i]==0)
                    {
                        f=0;
                        break;
                    }
                }
                for(int i=y1;i<=y2;++i)
                {
                    if(br[i]==0)
                    {
                        ok=0;
                        break;
                    }
                }
            }
            cout<<((!(f || ok)?"No":"Yes"))<<endl;
        }
    }
}
signed main()
{
    sol(); 
    return 0;
}