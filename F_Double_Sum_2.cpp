#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=25;
void sol()
{
    int n;
    cin>>n;
    int mxi=0;
    vector<vector<int>>Arr(25,vector<int>());
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        if(x==0)continue;
        int v=__builtin_ctz(x);
        int f=x>>v;
        Arr[v].push_back(f);
        if(v>mxi)mxi=v;
    }
    vector<int>F(25,0),count(25,0);
    for(int v=0;v<=mxi;++v)
    {
        count[v]=Arr[v].size();
        for(auto&f:Arr[v])F[v]+=f;
    }
    vector<int>powers(25,1);
    for(int i=1;i<25;++i)powers[i]=powers[i-1]*2;
    int result=0;
    for(int v1=0;v1<=mxi;++v1)
    {
        for(int v2=v1+1;v2<=mxi;++v2)
        {
            int term1=F[v1]*count[v2];
            int term2=F[v2]*count[v1]*powers[v2-v1];
            result+=term1+term2;
        }
    }
    for(int v=0;v<=mxi;++v)result+=F[v];
    for(int v=0;v<=mxi;++v)
    {
        if(Arr[v].empty())continue;
        vector<int>&Sv=Arr[v];
        sort(Sv.begin(),Sv.end());
        vector<pair<int,int>>freq;
        int n=Sv.size(),current=Sv[0],cnt=1;
        for(int i=1;i<n;++i)
        {
            if(Sv[i]==current)++cnt;
            else
            {
                freq.emplace_back(make_pair(current,cnt));
                current=Sv[i];
                cnt=1;
            }
        }
        freq.emplace_back(make_pair(current,cnt));
        int m=freq.size();
        for(int i=0;i<m;++i)
        {
            int a=freq[i].first,cnt_a=freq[i].second;
            if(cnt_a>=2)
            {
                int y=a+a;
                if(y==0)continue;
                int s=__builtin_ctz(y);
                int ok=y>>s;
                int pairs=(cnt_a*(cnt_a-1))/2;
                result+=pairs*ok;
            }
            for(int j=i+1;j<m;++j)
            {
                int b=freq[j].first,cnt_b=freq[j].second;
                int y=a+b;
                if(y==0)continue;
                int s=__builtin_ctz(y);
                int ok=y>>s;
                int pairs=cnt_a*cnt_b;
                result+=pairs*ok;
            }
        }
    }
    cout<<result<<endl;
}
signed main()
{
    sol();
    return 0;
}