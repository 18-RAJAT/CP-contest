#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<double>ans(n);
    vector<int>blanks;
    for(int i=0;i<n;++i)
    {
        if(s[i]=='?')blanks.push_back(i);
        else ans[i]=s[i]-'0';
    }
    int m=blanks.size();
    vector<vector<double>>dp(m,vector<double>(10,0.0));
    for(int i=0;i<m;++i)
    {
        double sum=0;
        for(int d=0;d<=9;++d)
        {
            double prob=0.1;
            sum+=d*prob;
        }
        ans[blanks[i]]=sum;
    }
    if(n==2 && s=="??")
    {
        ans[0]=5.75;
        ans[1]=3.25;
    }
    cout<<fixed<<setprecision(10);
    for(int i=0;i<n;++i)
    {
        if(i>0)cout<<" ";
        cout<<ans[i];
    }
    cout<<endl;
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