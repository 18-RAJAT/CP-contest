#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    map<char,int>pairs;
    for(auto& it:s)
    {
        pairs[it]++;
    }
    int mx=0;
    for(auto& value:pairs)
    {
        mx=max(mx,value.second);
    }
    int ans=n-mx;
    //if mx<=ans, then we can remove all the pairs, otherwise we can remove all the pairs except one pair
    cout<<((mx<=ans)?(n&1):mx-ans)<<endl;
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