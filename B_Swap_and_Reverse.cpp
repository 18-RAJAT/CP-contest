#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    string tmp=s;
    if(k%2)
    {
        vector<string>ans(2);
        ans[0]=ans[1]="";
        for(int i=0;i<n;++i)
        {
            ans[i%2]+=s[i];
        }
        sort(ans[0].begin(),ans[0].end());
        reverse(ans[0].begin(),ans[0].end());
        // sort(ans.begin(),ans.end());
        // reverse(ans.begin(),ans.end());
        sort(ans[1].begin(),ans[1].end());
        reverse(ans[1].begin(),ans[1].end());

        for(int i=0;i<n;++i)
        {
            cout<<ans[i%2].back();
            // if(i%2)
            // {
            //     tmp[i]=ans[1][i/2];
            // }
            // else
            // {
            //     tmp[i]=ans[0][i/2];
            // }
            ans[i%2].pop_back();
        }
        cout<<endl;
    }
    else
    {
        sort(s.begin(),s.end());
        // reverse(tmp.begin(),tmp.end());
        cout<<s<<endl;
    }
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