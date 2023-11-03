#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<string>s(n);
    for(int i=0;i<n;++i)
    {
        cin>>s[i];
    }
    // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    sort(s.begin(),s.end(),[&](string s,string t)->bool
    {
        return s.size()<t.size()?true:false;
    });
    int ans=0;
    map<pair<int,int>,int>mp;
    for(int i=0;i<n;++i)
    {
        auto convert=[&](char ch)->int
        {
            return ch-'0';
        };
        int cnt=0,chk=0;
        for(auto& ch:s[i])
        {
            cnt+=convert(ch);
        }
        int sza=s[i].size();
        ans+=mp[make_pair(sza,cnt)];
        // assert(~sza&1);
        for(int j=0;j<sza;++j)
        {
            chk+=convert(s[i][j]);
            int lucky=sza-j-1;
            int unlucky=j+1;
            // ~lucky&1?lucky--:lucky++;
            if(lucky==unlucky)
            {
                continue;
            }
            int tmp=cnt-chk;
            if(tmp<0)
            {
                continue;
            }
            ans+=mp[make_pair(unlucky-lucky,chk-(tmp))];
            ans+=mp[make_pair(lucky-unlucky,cnt-chk-chk)];
        }
        mp[make_pair(sza,cnt)]++;
    }
    cout<<ans+n<<endl;
}
signed main()
{
    sol();
    return 0;
}