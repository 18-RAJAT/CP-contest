#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    if(n&1)
    {
        if(n==1)
        {
            cout<<1<<endl;
            cout<<1<<" "<<1<<endl;
        }
        else if(n==3)
        {
            cout<<0<<endl;
            cout<<2<<" "<<1<<" "<<2<<endl;
        }
        else
        {
            cout<<1-((n/2)&1)<<endl;
            int p1=2,p2=n;
            cout<<n/2<<endl;
            int check=((n+1)/2)/2;
            while(check--)
            {
                cout<<p1<<" "<<p2<<" ";
                p1+=2,p2-=2;
                if(p1+1==p2&&((n/2)&1))
                {
                    cout<<p2<<endl;
                    return;
                }
            }
            cout<<endl;
        }
    }
    else
    {
        if(n==2)
        {
            cout<<1<<endl;
            cout<<1<<" "<<1<<endl;
        }
        else
        {
            cout<<((n/2)&1)<<endl;
            cout<<n/2<<" ";
            int p1=1,p2=n;
            int check=(n/2)/2;
            while(check--)
            {
                cout<<p1<<" "<<p2<<" ";
                p1+=2,p2-=2;
            }
            if((n/2)&1)
            {
                cout<<p2<<endl;
            }
        }
    }
}
signed main()
{
    sol();
    return 0;
}