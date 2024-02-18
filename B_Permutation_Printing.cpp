#include<bits/stdc++.h>
using namespace std;
void sol()
{
    long long n;
    cin>>n;
    long long a[n];
    memset(a,0,sizeof(a));
    long long int cnt=1;
    for(int i=0;i<n;i+=2)
    {
        a[i]=cnt;
        cnt++;
    }
    //reverse
    for(int i=n-1;i>=0;i--)
    {
        if(a[i]!=0)
        {
            continue;
        }
        a[i]=cnt;
        cnt++;
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
    return 0;
}