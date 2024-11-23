#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=998244353;
inline void add_mod(int &a,int b){a=(a+b)%MOD;}
void sol()
{
    int N,K;
    cin>>N>>K;
    string S;
    cin>>S;
    int NK=(N*(N+1))/2;
    NK=min(NK,1275LL);
    unordered_map<char,int>bits={{'A',1},{'B',2},{'C',4}};
    vector<vector<int>>ndp(8,vector<int>(NK+1,0));
    ndp[0][0]=1;
    vector<int>fz_p(8,0);
    fz_p[0]=1;
    for(int pos=0;pos<N;++pos)
    {
        vector<vector<int>>dp_new(8,vector<int>(NK+1,0));
        vector<int>freq_new(8,0);
        vector<char>pos_ch;
        if(S[pos]=='?') pos_ch={'A','B','C'};
        else pos_ch={S[pos]};
        for(int i=0;i<8;++i)
        {
            for(int j=0;j<=NK;++j)
            {
                if(ndp[i][j]==0) continue;
                for(auto &c:pos_ch)
                {
                    int sym=i^bits[c];
                    int goal=fz_p[sym]+fz_p[sym^7];
                    goal%=MOD;
                    int ok=j+goal;
                    if(ok>NK) continue;
                    add_mod(dp_new[sym][ok],ndp[i][j]);
                }
            }
        }
        for(int s=0;s<8;++s)
        {
            for(int k=0;k<=NK;++k)
            {
                if(dp_new[s][k])add_mod(freq_new[s],dp_new[s][k]);
            }
        }
        ndp=move(dp_new);
        fz_p=move(freq_new);
    }
    int ans=0;
    for(int s=0;s<8;++s)
    {
        for(int k=K;k<=NK;++k)
        {
            add_mod(ans,ndp[s][k]);
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}