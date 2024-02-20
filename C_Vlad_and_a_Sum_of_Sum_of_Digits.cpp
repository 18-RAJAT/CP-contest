#include<bits/stdc++.h>
using namespace std;
#define int long long
int arr[2000005];
void func()
{
    for(int i=1;i<=2000000;++i)
    {
        int x=i;
        if(x>=10)
        {
            int sum=0;
            while(x)
            {
                sum+=x%10;
                x/=10;
            }
            x=sum;
        }
        arr[i]=arr[i-1]+x;
    }
}
void sol()
{
    int n;
    cin>>n;
    cout<<arr[n]<<endl;
}
signed main()
{
    func();
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
    return 0;
}