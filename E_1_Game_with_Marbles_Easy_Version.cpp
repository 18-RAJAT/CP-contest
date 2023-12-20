#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;++i)
    {
        cin>>b[i];
    }
    function<int(vector<int>&,vector<int>&,int)>rec=[&](vector<int>&a,vector<int>&b,int idx)->int
    {
        int ans=idx?1e18:-1e18;
        int sza=a.size();
        for(int j=0;j<sza;++j)
        {
            if(a[j]>=1 && b[j]>=1)
            {
                if(idx==0)
                {
                    int A=a[j],B=b[j];
                    a[j]--;
                    b[j]=0;
                    ans=max<int>(ans,rec(a,b,1));
                    a[j]=A;
                    b[j]=B;
                }
                else
                {
                    int A=a[j],B=b[j];
                    a[j]=0;
                    b[j]--;
                    ans=min<int>(ans,rec(a,b,0));
                    a[j]=A;
                    b[j]=B;
                }
            }
        }
        if(ans==1e18 || ans==-1e18)
        {
            int SA=0,SB=0;
            for(int j=0;j<sza;++j)
            {
                SA+=a[j],SB+=b[j];
            }
            ans=SA-SB;
        }
        return ans;
    };
    cout<<rec(a,b,0)<<endl;
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