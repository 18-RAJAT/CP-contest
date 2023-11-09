#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    int chef=0,chefina=0;
    for(int i=0;i<n;++i)
    {
        if(a[i]==b[i])
        {
            continue;
        }
        else if(a[i]=='R' && b[i]=='S')
        {
            chef++;
        }
        else if(a[i]=='S' && b[i]=='P')
        {
            chef++;
        }
        else if(a[i]=='P' && b[i]=='R')
        {
            chef++;
        }
        else if(a[i]=='S' && b[i]=='R')
        {
            chefina++;
        }
        else if(a[i]=='P' && b[i]=='S')
        {
            chefina++;
        }
        else if(a[i]=='R' && b[i]=='P')
        {
            chefina++;
        }
    }
    int count=0;
    while(chef<=chefina)
    {
        count++;
        chef++;
        chefina--;
    }
    cout<<count<<endl;
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