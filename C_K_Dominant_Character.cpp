#include<bits/stdc++.h>
using namespace std;
#define int long long
int arr[100005],dp[100005][26];
int check[26];
string s;
int binarySearch(int val)
{
    for(int i=1;i<26;++i)
    {
        check[i]=1;
    }
    for(int i=1;i<s.size()-1;++i)
    {
        int x=i+val-1;
        for(int j=1;j<26;++j)
        {
            if(dp[x][j]-dp[i-1][j]==0)
            {
                check[j]=0;
            }
        }
    }
    for(int i=1;i<26;++i)
    {
        if(check[i])
        {
            return 1;
        }
    }
    return 0;
}
void sol()
{
   cin>>s;
   s="#"+s;
   for(int i=1;i<s.size()-1;++i)
    {
    //    arr[i]=s[i]-'a'+1;
       for(int j=1;j<26;++j)
        {
           dp[i][j]+=dp[i-1][j];
        }
         dp[i][s[i]-'a'+1]++;
    }
    int ans=1;
    int l=1,r=s.size();
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(binarySearch(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    if(ans>1)
    {
        cout<<ans-dp[s.size()-2][s[s.size()-1]-'a'+1]-1<<endl;
        return;
    }
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}