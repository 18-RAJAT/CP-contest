#include<bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    return gcd(b,a%b);
}
void sol()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    int sum=0;
    int f1=0,f2=0,f3=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        sum+=a[i];
        if(a[i]==k)
        {
            f1=1;
        }
        else if(a[i]>k)
        {
            f2=1;
        }
        else
        {
            f3=1;
        }
    }
    if(f1+f2+f3>=2)
    {
        cout<<"-1\n";
        return;
    }
    if(f1==1)
    {
        cout<<"0\n";
        return;
    }
    int tmp=a[0];
    //gcd
    int diff=abs<int>(k-tmp);
    for(int i=0;i<n;++i)
    {
        diff=gcd(diff,abs<int>(k-a[i]));
    }
    int ert;
    f2?ert=diff+k:ert=k-diff;
    int chk=k-ert;
    cout<<(n*ert-sum)/chk<<"\n";
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
