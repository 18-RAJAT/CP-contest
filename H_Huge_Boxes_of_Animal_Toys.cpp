#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==0 && b==0 && c==0 && d==0)
    {
        puts("Tidak Tidak Tidak Tidak");
    }
    if(a==0 && b==0 && c!=0 && d==0)
    {
        puts("Tidak Tidak Ya Tidak");
    }
    else if(a==0 && b==0 && c==0 && d!=0)
    {
        puts("Tidak Tidak Tidak Ya");
    }
    else if(a!=0 && b==0 && c==0 && d==0)
    {
        if(a%2==0)
        {
            puts("Tidak Tidak Tidak Ya");
        }
        else
        {
            puts("Ya Tidak Tidak Tidak");
        }
    }
    else if(a==0 && b!=0 && c==0 && d==0)
    {
        if(b%2==0)
        {
            puts("Tidak Tidak Ya Tidak");
        }
        else
        {
            puts("Tidak Ya Tidak Tidak");
        }
    }
    else
    {
        int a1=a,b1=b,c1=c,d1=d;
        int ctr=1;
        if(a1&1)
        {
            ctr*=-1;
        }
        if(b1&1)
        {
            ctr*=-1;
        }
        if(c1&1)
        {
            ctr*=1;
        }
        if(d1&1)
        {
            ctr*=1;
        }
        if(ctr>=1)
        {
            if(a==0 && b>=1 && c>=1 && d==0)
            {
                puts("Tidak Tidak Ya Tidak");
            }
            else if(c>=1 || b>=1)
            {
                puts("Tidak Tidak Ya Ya");
            }
            else
            {
                puts("Tidak Tidak Tidak Ya");
            }
        }
        else
        {
            if(a==0 && b>=1 && c>=1 && d==0)
            {
                puts("Tidak Ya Tidak Tidak");
            }
            else if(b>=1 || c>=1)
            {
                puts("Ya Ya Tidak Tidak");
            }
            else
            {
                puts("Ya Tidak Tidak Tidak ");
            }
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