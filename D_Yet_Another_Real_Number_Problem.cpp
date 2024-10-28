#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=1000000007;

int power(int a,int b,int mod=MOD)
{
    int res=1;
    a%=mod;
    while(b)
    {
        if(b&1)
        {
            res=(res*a)%mod;
        }
        a=(a*a)%mod;
        b/=2;
    }
    return res%mod;
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>a(n+1);
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
        }
        stack<pair<int,int>>st;
        int in=0,not_in=0;

        for(int i=1;i<=n;++i)
        {
            int temp=a[i],ok=0;
            while(temp%2==0)
            {
                temp/=2;
                ok++;
            }
            while(!st.empty())
            {
                const auto& tp=st.top();
                int x=tp.first,y=tp.second;
                int realNum=ok<32?(1LL<<ok)*temp:1e18;
                if(x>realNum) break;
                st.pop();
                in=(in+MOD-(x*power(2,y)%MOD))%MOD;
                ok+=y;
                not_in=(not_in+x)%MOD;
            }
            st.push({temp,ok});
            in=(in+(temp*power(2,ok))%MOD)%MOD;
            cout<<(in+not_in)%MOD;
            if(i!=n) cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}