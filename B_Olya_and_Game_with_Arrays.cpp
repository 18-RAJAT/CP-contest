#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        long long mn=INT_MAX;
        vector<long long>ans;
        for(long long i=0;i<n;++i)
        {
            long long x;
            cin>>x;
            // mn=min<long long>(mn,x);
            // ans.push_back(x);
            vector<long long>tp(x);
            for(long long j=0;j<x;++j)
            {
                cin>>tp[j];
            }
            sort(tp.begin(),tp.end());
            mn=min<long long>(mn,tp[0]);
            ans.push_back(tp[1]);
        }
        sort(ans.begin(),ans.end());
        ans[0]=mn;
        long long res=0;
        for(long long i=0;i<ans.size();++i)
        {
            res+=ans[i];
        }
        cout<<res<<"\n";
    }
}