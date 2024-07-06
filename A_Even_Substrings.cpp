#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int sum=0;
    for(int i=0;i<s.length();++i)
    {
        if((s[i]-48)%2==0)
        {
            sum+=(i+1);
        }
    }
    cout<<sum;
}
signed main()
{
    sol();
    return 0;
}