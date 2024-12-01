#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string S,T;
    cin>>S>>T;
    int s=S.size(),t=T.size(),K=min(1000LL,s+t);
    unordered_map<string,unordered_set<int>>mp;
    int res=s+t+1;
    string ans="-1";
    for(int L=2;L<=K;++L)
    {
        for(int i=1;i<L;++i)
        {
            if(i>s || (L-i)>t)continue;
            string prefix=S.substr(0,i),suffix=T.substr(t-(L-i));
            string tmp=prefix+suffix;
            if(S.find(prefix)!=0 || T.rfind(suffix)!=(t-suffix.size()))continue;
            mp[tmp].insert(i);
            if(mp[tmp].size()>=2)
            {
                if(tmp.size()<res)
                {
                    res=tmp.size();
                    ans=tmp;
                }
                else if(tmp.size()==res && tmp<ans)ans=tmp;
            }
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}