#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[20][10][2][2][2];//dp[i][j][k][l][m] means the number of numbers with length i, first digit j, last digit k, whether the number is less than r l, whether the number is greater than l m
int sol(int index,int first,int last,string& l,string& r,int top,int down)
{
    if(index==l.size())
    {
        return first==last && ~first;
    }
    int& ans=dp[index][first+1][last+1][top][down];
    int start=0,end=0;
    if(~ans)
    {
        return ans;
    }
    if(top)
    {
        start=0;
    }
    else
    {
        start=l[index]-'0';
    }
    if(down)
    {
        end=9;
    }
    else
    {
        end=r[index]-'0';
    }
    int vals=0;
    for(int i=start;i<=end;++i)
    {
        if(first==-1 && i!=0)
        {
            vals+=sol(index+1,i,(i==0 && index==l.size()-1)?-1:i,l,r,top || i>l[index]-'0',down || i<r[index]-'0');
        }
        else if(i==0 && index==l.size()-1)
        {
            vals+=sol(index+1,first,-1,l,r,top || i>l[index]-'0',down || i<r[index]-'0');
        }
        else
        {
            vals+=sol(index+1,first,(i==0 && index==l.size()-1)?-1:i,l,r,top || i>l[index]-'0',down || i<r[index]-'0');
        }
    }
    return ans=vals;
}
signed main()
{
    string l,r;
    cin>>l>>r;
    memset(dp,-1,sizeof(dp));
    while(l.size()<r.size())
    {
        l="0"+l;
    }
    cout<<sol(0,-1,-1,l,r,0,0)<<"\n";
    return 0;
}