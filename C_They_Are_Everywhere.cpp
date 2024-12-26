#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    map<char,int>freq;
    for(auto& it:s)freq[it]++;
    int sza=freq.size();
    freq.clear();
    int l=0,r=0,ans=n,cnt=0;
    while(r<n)
    {
        if(!freq[s[r]])cnt++;
        freq[s[r]]++;
        while(l<=r && freq[s[l]]>=2)freq[s[l++]]--;
        if(cnt==sza)ans=min(ans,r-l+1);
        r++;
    }
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}