#include<bits/stdc++.h>
using namespace std;
#define int long long int
void sol()
{
    int n,m,k;
    cin>>n>>m>>k;
    set<int>a,b;
    int sumA=0,sumB=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a.insert(x);
        sumA+=(long long)x;
    }
    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        b.insert(x);
        sumB+=(long long)x;
    }
    if(k&1)
    {
        int amin=*a.begin();
        int bmax=*b.rbegin();
        if(amin<bmax)
        {
            b.insert(amin);
            // b.insert(bmax);
            b.erase(bmax);
            a.insert(bmax);
            a.erase(amin);
            sumA+=(bmax-amin);
            sumB-=(bmax-amin);
        }
        k--;
        int prA=-1,prB=-1;
        while(k && (sumA!=prA || sumB!=prB))
        {
            prA=sumA;
            prB=sumB;
            k-=2;

            int amx=*a.rbegin();
            int bmin=*b.begin();
            if(amx>bmin)
            {
                b.insert(amx);
                b.erase(bmin);
                a.insert(bmin);
                a.erase(amx);
                sumA-=(amx-bmin);
                sumB+=(amx-bmin);
            }
            int amin=*a.begin();
            int bmax=*b.rbegin();
            if(bmax>amin)
            {
                b.insert(amin);
                b.erase(bmax);
                a.insert(bmax);
                a.erase(amin);
                sumA+=(bmax-amin);
                sumB-=(bmax-amin);
            }
        }
        cout<<sumA<<"\n";
    }
    else
    {
        int prA=-1,prB=-1;
        while(k && (sumA!=prA || sumB!=prB))
        {
            prA=sumA;
            prB=sumB;
            k-=2;
            int amin=*a.begin();
            int bmax=*b.rbegin();
            if(bmax>amin)
            {
                b.insert(amin);
                b.erase(bmax);
                a.insert(bmax);
                a.erase(amin);
                sumA+=(bmax-amin);
                sumB-=(bmax-amin);
            }
            int amx=*a.rbegin();
            int bmin=*b.begin();
            if(amx>bmin)
            {
                b.insert(amx);
                b.erase(bmin);
                a.insert(bmin);
                a.erase(amx);
                sumA-=(amx-bmin);
                sumB+=(amx-bmin);
            }
        }
        cout<<sumA<<"\n";
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