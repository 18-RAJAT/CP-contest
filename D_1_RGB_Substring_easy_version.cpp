#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int ans=1e18;
    string pairs[3]={"RGB","GBR","BRG"};
    for(int i=0;i<=n-k;++i)
    {
        for(int j=0;j<3;++j)
        {
            string temp="";
            while(temp.size()<k)
            {
                temp+=pairs[j];
            }
            while(temp.size()>k)
            {
                temp.pop_back();
            }
            int ert=k;
            int count=0;
            for(int l=i;l<i+k;++l)
            {
                s[l]!=temp[count]?ert++:ert--;
                count++;
            }
            ans=min<int>(ans,ert);
        }
    }
    cout<<ans/2<<'\n';
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