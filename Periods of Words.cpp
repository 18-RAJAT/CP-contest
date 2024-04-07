#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int>lps(n);
    int l=0,r=-1;
    for(int i=0;i<n;++i)
    {
        int k=(i>r)?1:min(lps[l+r-i],r-i+1);
        while(i-k>=0 && i+k<n && s[i-k]==s[i+k])k++;
        lps[i]=k--;
        if(i+k>r)l=i-k,r=i+k;
    }
    int ans=0;
    for(int i=0;i<n;++i)
    {
        ans+=lps[i];
    }
    cout<<ans+n/2;
}
signed main()
{
    sol();
    return 0;
}