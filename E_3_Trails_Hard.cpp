#include<bits/stdc++.h>
using namespace std;
#define int long long
const  int MAX=105;
// Time Complexity=O(m + m^2 + logn ⋅ MAX^3) = O(m + m^2 + logn ⋅ 105^3) = O(m + m^2 + logn ⋅ 1157625) = O(m + m^2 + logn) => O(m^2 + logn)
// Space Complexity=O(m + MAX^2) = O(m + 105^2) = O(m + 11025) => O(m)

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
    //matrix multiplication O(MAX^3)
    matrix operator*(const matrix &mat)const
    {
        matrix ans;
        for(int i=0;i<MAX;++i)
        {
            for(int j=0;j<MAX;++j)
            {
                for(int k=0;k<MAX;++k)
                {
                    ans.dp[i][j]=(ans.dp[i][j]+(dp[i][k]*mat.dp[k][j])%1000000007)%1000000007;
                }
            }
        }
        return ans;
    }
};
//binary exponentiation O(logb⋅MAX^3)
matrix binary_exp(matrix a,int b)
{
    matrix ans;
    ans.state();
    while(b>=1)
    {
        if(b&1)ans=ans*a;
        a=a*a,b/=2;
    }
    return ans;
}
class recur
{
private:
    int m,n;
    vector<int>s,l;

public:
    matrix temp;
    recur(int m,int n):m(m),n(n),s(m),l(m){}

    void take()
    {
        for(auto& it:s)cin>>it;
        for(auto& it:l)cin>>it;
    }
    void init_matrix()
    {
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<m;++j)
            {
                temp.dp[i][j]=(s[i]*s[j])+(s[i]*l[j])+(l[i]*s[j]);
            }
        }
    }
    int E2()
    {
        int ans=0;
        matrix res=binary_exp(temp,n);
        for(int i=0;i<m;++i)ans=(ans+res.dp[0][i])%1000000007;
        return ans;
    }
    ~recur(){}
};
void sol()
{
    int m,n;
    cin>>m>>n;
    recur calculate(m,n);
    calculate.take();
    calculate.init_matrix();
    cout<<calculate.E2()<<endl;
}
signed main()
{
    sol();
    return 0;
}