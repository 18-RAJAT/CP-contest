#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s,p;
    cin>>s>>p;
    tuple<int,int,int>z;
    vector<int>lps;
    function<void(string)>z_algo=[&](string s)
    {
        int n=s.size();
        lps.resize(n+1);
        lps[0]=0;
        for(int i=1,j=0;i<=n;++i)
        {
            auto &k=lps[i];
            k=(j+lps[j]<=i)?0:min(j+lps[j]-i,lps[i-j]);
            while(i+k<n && s[k]==s[i+k])k++;
            if(j+lps[j]<i+lps[i])j=i;
        }
        lps[0]=n;
    };
    z_algo(p);
    int n=s.size(),m=p.size();
    int ans=0;
    for(int i=0,j=0;i<n;++i)
    {
        auto &k=get<0>(z);
        k=(j+lps[j]<=i)?0:min(j+lps[j]-i,lps[i-j]);
        while(i+k<n && j+k<m && s[i+k]==p[j+k])k++;
        if(j+lps[j]<i+lps[i])j=i;
        if(k==m)ans++;
    }
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}