#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int sum=0,i=1;
    while(1)
    {
        if(i&1)sum-=2*i-1;
        else sum+=2*i-1;
        if(sum>n)
        {
            cout<<"Kosuke"<<endl;
            break;
        }
        if(sum<-n)
        {
            cout<<"Sakurako"<<endl;
            break;
        }
        i++;
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