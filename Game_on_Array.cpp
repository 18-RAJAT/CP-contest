#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int a[n];
    // int sum=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        // sum+=a[i];
    }
    int even=0,odd=0;
    if(n==1)
    {
        if(a[0]==1)
        {
            cout<<"Bob"<<endl;
            return;
        }
        else
        {
            cout<<"Alice"<<endl;
            return;
        }
    }
    for(int i=0;i<n;++i)
    {
        i%2==0?even+=a[i]:odd+=a[i];
    }
    int total=even+odd;
    //calculate the number of even and odd numbers in the array and then check if the total sum is even or odd and then check if the number of even numbers is even or odd
    ((total&1) || ((total/2)%2==even%2))?cout<<"Bob"<<endl:cout<<"Alice"<<endl;
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