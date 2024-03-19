#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    string str=" ";
    str+=s;
    int count_zero=0,count_one=0;
    int ans=1e9,idx=-1;
    for(int i=1;i<=n;++i)
    {
        count_one+=str[i]=='1';
    }
    for(int i=0;i<=n+1;++i)
    {
        if(i!=0 && i!=n+1)
        {
            count_zero+=str[i]=='0';
            count_one-=str[i]=='1';
        }
        int zero=i/2+i%2;
        int one=(n-i)/2+(n-i)%2;
        if(count_zero>=zero && count_one>=one)
        {
            if(abs(n-2*i)<ans)
            {
                ans=n-2*i;
                idx=i;
            }
        }
    }
    cout<<idx<<endl;
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