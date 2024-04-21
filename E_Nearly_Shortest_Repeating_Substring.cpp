#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    function<vector<int>(int)>divisors=[&](int n)->vector<int>
    {
        vector<int>v;
        for(int i=1;i*i<=n;++i)
        {
            if(n%i==0)
            {
                v.push_back(i);
                if(n!=i*i)
                {
                    v.push_back(n/i);
                }
            }
        }
        return v;
    };
    vector<int>fact=divisors(n);
    sort(fact.begin(),fact.end());
    vector<string>F,B;
    string temp="";
    for(int i=0;i<fact.size();++i)
    {
        for(int j=0;j<fact[i];++j)
        {
            temp+=s[j];
        }
        F.push_back(temp);
        temp.clear();
    }
    temp.clear();
    for(int i=0;i<fact.size();++i)
    {
        for(int j=n-1;j>=n-fact[i];--j)
        {
            temp+=s[j];
        }
        reverse(temp.begin(),temp.end());
        B.push_back(temp);
        temp.clear();
    }
    int ans1=n,ans2=n;
    for(int i=0;i<F.size();++i)
    {
        int cal1=0,cal2=0;
        for(int j=0;j<n;++j)
        {
            if(F[i][j%F[i].size()]!=s[j])
            {
                cal1++;
            }
        }
        if(cal1<=1)
        {
            ans1=F[i].size();
            break;
        }
    }
    for(int i=0;i<B.size();++i)
    {
        int val=0;
        for(int j=n-1;j>=0;--j)
        {
            if(s[j]!=B[i][j%B[i].size()])
            {
                val++;
            }
        }
        if(val<=1)
        {
            ans2=B[i].size();
            break;
        }
    }
    cout<<min(ans1,ans2)<<endl;
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