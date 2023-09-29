#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[10][200010];
/*
    Approach:
    We need to find the length of the number after applying m operations.
    So, we need to find the number of digits in the number after applying m operations.
    We can precompute the number of digits in the number after applying m operations for all the digits from 0 to 9.
    Then, we can find the number of digits in the number after applying m operations by adding the number of digits in the number after applying m operations for each digit in the number.
    We can precompute the number of digits in the number after applying m operations for all the digits from 0 to 9 by using dp.
    dp[i][j] represents the number of digits in the number after applying j operations for the digit i.
    dp[i][j]=dp[i+1][j-1] for i from 0 to 8
    dp[9][j]=dp[0][j-1]+dp[1][j-1] for i from 0 to 8
    dp[i][0]=1 for i from 0 to 9
    We can find the number of digits in the number after applying m operations by adding the number of digits in the number after applying m operations for each digit in the number.
    We can find the number of digits in the number after applying m operations for each digit in the number by using the above dp array.
*/
void precompute()
{
    for(int i=0;i<=9;++i)
    {
        dp[i][0]=1;
    }
    for(int i=1;i<=200010;++i)
    {
        for(int j=0;j<=9;++j)
        {
            if(j==9)//dp[9][i]=dp[0][i-1]+dp[1][i-1]
            {
                dp[j][i]=((dp[0][i-1])%1000000007+(dp[1][i-1])%1000000007)%1000000007;
            }
            else
            {
                dp[j][i]=(dp[j+1][i-1])%1000000007;
                // cout<<dp[j][i]<<" ";
            }
        }
    }
    // cout<<"comp: "<<dp[0][1]<<" "<<dp[1][1]<<"\n";
}
void sol()
{
    int n,m;
    cin>>n>>m;
    int calculate=0%1000000007;
    while(n)
    {
        calculate=((calculate%1000000007)+((dp[n%10][m])%1000000007)%1000000007);
        n/=10;
    }
    cout<<calculate%1000000007<<"\n";
}
signed main()
{
    int t;
    cin>>t;
    precompute();
    while(t--)
    {
        sol();
    }
    return 0;
}