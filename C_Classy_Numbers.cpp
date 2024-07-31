#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[20][5][2];
int recur(string& s,int idx,int cnt,int i)
{
    if(cnt>=4)return 0;
    if(idx==s.size())return 1;
    int ans=0;
    int& ret=dp[idx][cnt][i];
    if(~ret)return ret;
    for(char it:string("0123456789").substr(0,(i?s[idx]:'9')-'0'+1))
    {
        ans+=recur(s,idx+1,cnt+(it!='0'),i && (it==s[idx]));
    }
    return ret=ans;
}
void sol()
{
    int l,r;
    cin>>l>>r;
    assert(l>=0 && r>=0 && l<=r);
    l--;
    string L=to_string(l),R=to_string(r);
    fill(&dp[0][0][0],&dp[0][0][0]+sizeof(dp)/sizeof(dp[0][0][0]),-1);
    int L_num=recur(L,0,0,1);
    fill(&dp[0][0][0],&dp[0][0][0]+sizeof(dp)/sizeof(dp[0][0][0]),-1);
    int R_num=recur(R,0,0,1);
    cout<<R_num-L_num<<endl;
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