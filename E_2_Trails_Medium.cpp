#include<bits/stdc++.h>
using namespace std;
#define int long long
const  int MAX=105;
class matrix
{
    public:
    int dp[MAX][MAX];
    matrix()
    {
        memset(dp,0,sizeof(dp));
    }
    void state()
    {
        for(int i=0;i<MAX;++i)dp[i][i]=1;
    }
    matrix operator*(const matrix &mat)const
    {
        matrix ans;
        
    }
};
void sol()
{
    
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