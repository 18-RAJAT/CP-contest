#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int left=0,right=0;
    int i=0;
    while(s[i]==s[0])
    {
        left++;
        i++;
    }
    i=n-1;
    while(s[i]==s[n-1])
    {
        right++;
        i--;
    }
    if(s[0]==s[n-1])
    {
        cout<<(left+1ll)*(right+1ll)%998244353<<endl;
    }
    else
    {
        cout<<(left+right+1ll)%998244353<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}