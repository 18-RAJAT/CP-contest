#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ans=0;
    for(int i=0;i<n/2;++i)
    {
        int j=0;
        while(j<=i)
        {
            if(s[j]!=s[j+i+1]){break;}j++;
        }
        if(i<j)ans=max(ans,i);
    }
    cout<<n-ans;
}
signed main()
{
    sol();
    return 0;
}