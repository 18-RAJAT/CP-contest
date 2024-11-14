#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int ans=0;
    for(int i=0;i<(k+1)/2;++i)
    {
        vector<int>fz(26);
        for(int j=0;j<n;j+=k)
        {
            fz[s[i+j]-'a']++;
            if(i+j!=j+k-1-i)fz[s[j+k-1-i]-'a']++;
        }
        int sum=accumulate(fz.begin(),fz.end(),0LL);
        ans+=sum-*max_element(fz.begin(),fz.end());
    }
    cout<<ans<<endl;
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