#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    int k;
    cin>>s>>k;
    int n=s.size(),zero=0,i=0;
    for(i=n-1;i>=0;--i)
    {
        if(s[i]=='0')zero++;
        if(zero==k)
        {
            break;
        }
    }
    cout<<((zero==k)?i++,(n-i+1)-k:n-1);
}
signed main()
{
    sol();
    return 0;
}