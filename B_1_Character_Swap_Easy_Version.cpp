#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string a,b;
        cin>>a>>b;
        int c(0),p1,p2;
        for(int i=0;i<n;i++)
        {
            if(a[i]!=b[i])
            {
                if(c==0)
                {
                    p1=i;
                }
                else
                {
                    p2=i;
                }
                c++;
            }
        }
        if(c!=2)
        {
            cout<<"No\n";
        }
        else
        {
            if(a[p1]==a[p2] && b[p1]==b[p2])
            {
                cout<<"Yes\n";
            }
            else
            {
                cout<<"No\n";
            }
        }
    }
    return 0;
}