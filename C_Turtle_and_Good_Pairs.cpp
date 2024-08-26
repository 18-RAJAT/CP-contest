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
    vector<int>count(26,0);
    for(auto& it:s)count[it-'a']++;
    for(int i=0;i<26;++i)
    {
        ans+=(count[i]==0?true:false);
    }
    for(;ans<26;)
    {
        for(int i=0;i<26;++i)
        {
            if(count[i])
            {
                cout<<(char)(i+'a');
                if(--count[i]==0)ans++;
            }
        }
    }
    cout<<endl;
    return;
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