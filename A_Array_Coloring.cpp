#include<bits/stdc++.h>
using namespace std;
#define ll long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int parity=0;
    for(int i=0;i<n;++i)
    {
        parity+=a[i];
    }
    if(parity%2==0)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
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