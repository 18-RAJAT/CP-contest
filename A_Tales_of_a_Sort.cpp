#include<bits/stdc++.h>
using namespace std;
void sol()
{
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(a,a+n);
    for(int i=n-1;i>=0;i--)
    {
        if(a[i]!=b[i])
        {
            cout<<a[i]<<"\n";
            return;
        }
    }
    cout<<0<<"\n";
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
}